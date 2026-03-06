import pandas as pd
from pathlib import Path
import re
import html
from typing import Dict, List, Tuple

class BuildWebsite:
    
    SECTION_KEYS = [
        'Título', 'Topicos do problema', 'Tempo limite de execução', 
        'Descrição', 'Formato da entrada', 'Formato da saída'
    ]
    QUESTION_PATTERN = re.compile(r'^question(\d+)$')
    BASE_GITHUB_PATH = "/create-code-and-judge-code-with-llms/database/questions/"

    def __init__(self):
        """Inicializa os caminhos e constrói o site automaticamente."""
        self.questions_dir = Path("database/questions")
        self.output_dir = Path("frontend/docs")
        
        self.key_pattern = re.compile(
            r'^(%s):' % '|'.join(re.escape(k) for k in self.SECTION_KEYS), 
            re.MULTILINE
        )

        print("Iniciando a geração do site...")
        try:
            self._build_site()
            print("✅ Site criado com sucesso!")
        except Exception as e:
            print(f"❌ Erro crítico ao criar o site: {e}")

    def _build_site(self) -> None:
        """Orquestra o processo principal de construção do site."""
        self.output_dir.mkdir(parents=True, exist_ok=True)
        
        if not self.questions_dir.is_dir():
            raise FileNotFoundError(f"O diretório '{self.questions_dir}' não foi encontrado.")

        question_links = {}

        for item in self.questions_dir.iterdir():
            if not item.is_dir():
                continue

            match = self.QUESTION_PATTERN.match(item.name)
            if match:
                question_id = int(match.group(1))
                question_data = self._process_question_folder(item, question_id)
                
                if question_data:
                    question_links[question_id] = question_data

        if question_links:
            self._generate_index_file(question_links)
        else:
            print("\nNenhuma pasta de questão válida encontrada para gerar o índice.")

    def _process_question_folder(self, folder_path: Path, question_id: int) -> dict:
        """Processa uma pasta de questão individual e gera a sua página HTML."""
        problem_file = folder_path / "problem.txt"
        
        if not problem_file.is_file():
            print(f"  AVISO: {folder_path.name} não contém 'problem.txt'. Pulando.")
            return None

        print(f"  Processando {folder_path.name}...")
        
        try:
            # 1. Extrair ficheiros de input e output
            inputs = self._get_text_files(folder_path / "inputs", f"{folder_path.name}/inputs")
            outputs = self._get_text_files(folder_path / "outputs", f"{folder_path.name}/outputs")

            # 2. Fazer o parse do texto do problema
            sections = self._parse_problem_text(problem_file)
            
            # 3. Limpar os dados extraídos
            title_raw = sections.get('Título', 'Sem Título')
            title = re.sub(r'<[^>]+>', '', title_raw).strip()
            topics_str = sections.get('Topicos do problema', '')

            # 4. Formatar HTML das secções
            card_descricao = self._build_description_html(sections)
            card_entrada = sections.get('Formato da entrada', '<p>Não especificado.</p>')
            card_saida = sections.get('Formato da saída', '<p>Não especificado.</p>')

            # 5. Gerar e salvar a página HTML da questão
            html_content = self._create_question_page(
                question_id=str(question_id),
                card_descricao_html=card_descricao,
                card_entrada_html=card_entrada,
                card_saida_html=card_saida,
                inputs_paths=inputs,
                outputs_paths=outputs,
                topics_str=topics_str
            )
            
            output_file = self.output_dir / f"{folder_path.name}.html"
            output_file.write_text(html_content, encoding='utf-8')

            # Retorna os dados para a página Index
            return {
                'path': output_file, 
                'title': title, 
                'topics': topics_str
            }

        except Exception as e:
            print(f"    ERRO ao processar {folder_path.name}: {e}")
            return None

    def _get_text_files(self, target_dir: Path, relative_prefix: str) -> List[str]:
        """Procura e retorna caminhos relativos de ficheiros .txt num diretório."""
        files = []
        if target_dir.is_dir():
            for f in target_dir.iterdir():
                if f.is_file() and f.suffix == '.txt':
                    files.append(f"{relative_prefix}/{f.name}")
        return files

    def _parse_problem_text(self, file_path: Path) -> Dict[str, str]:
        """Lê o ficheiro problem.txt e separa os conteúdos baseado nas SECTION_KEYS."""
        text = file_path.read_text(encoding='utf-8')
        sections = {}
        last_pos = 0
        matches = list(self.key_pattern.finditer(text))
        
        for i, match in enumerate(matches):
            start_pos = match.end(1) + 1 
            if i > 0:
                prev_key = matches[i-1].group(1)
                sections[prev_key] = text[last_pos:match.start()].strip()
            last_pos = start_pos
        
        if matches:
            last_key = matches[-1].group(1)
            sections[last_key] = text[last_pos:].strip()
            
        return sections

    def _build_description_html(self, sections: dict) -> str:
        """Constrói o HTML da descrição combinando Título, Tempo e Texto."""
        parts = []
        if sections.get('Título'):
            parts.append(f"<h2>{sections.get('Título')}</h2>")
        if sections.get('Tempo limite de execução'):
            parts.append(f"<p><strong>Tempo limite:</strong> {sections.get('Tempo limite de execução')}</p>")
        if sections.get('Descrição'):
            parts.append(sections.get('Descrição'))
            
        return "\n".join(parts) if parts else "<p>Descrição não encontrada.</p>"

    def _generate_index_file(self, question_links: dict) -> None:
        """Gera e salva o ficheiro index.html principal."""
        sorted_links = dict(sorted(question_links.items()))
        html_content = self._create_index_page(sorted_links)
        
        index_path = self.output_dir / "index.html"
        index_path.write_text(html_content, encoding='utf-8')
        print(f"\nPágina principal 'index.html' gerada com sucesso em '{self.output_dir}'.")

    def _create_index_page(self, question_links: dict) -> str:
        list_items = ""
        for q_id, data in question_links.items():
            folder_name = data['path'].parent.name 
            title = data.get('title', 'Título não encontrado')
            topics_str = data.get('topics', '')
            
            link_text = f"Questão {q_id}: {title}" 
            
            topics_html = ""
            if topics_str:
                topics_list = [t.strip() for t in topics_str.split(';') if t.strip()]
                for topic in topics_list:
                    topics_html += f'<span class="ml-2 bg-gray-200 text-gray-700 px-2 py-0.5 rounded-full text-xs font-medium">{topic}</span>'

            list_items += f"""
            <li class="mb-2 py-1" data-title="{html.escape(title.lower())} {html.escape(folder_name.lower())} {html.escape(topics_str.lower())}">
                <a href="{data['path'].name}" class="text-blue-600 hover:text-blue-800 hover:underline">{link_text}</a>
                {topics_html}
            </li>
            """

        return f"""
    <!DOCTYPE html>
    <html lang="pt-br">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Lista de Questões - TCC</title>
        <script src="https://cdn.tailwindcss.com"></script>
        <link href="https://fonts.googleapis.com/css2?family=Inter:wght@400;500;600;700&display=swap" rel="stylesheet">
        <link rel="icon" type="image/png" href="/create-code-and-judge-code-with-llms/frontend/imgs/logo.png">
        <style> 
            body {{ font-family: 'Inter', sans-serif; }} 
            .copy-btn {{
                position: absolute;
                top: 0.5rem;
                right: 0.5rem;
                background-color: #4B5563;
                color: white;
                padding: 0.25rem 0.5rem;
                border-radius: 0.375rem;
                font-size: 0.75rem;
                font-weight: 500;
                opacity: 0;
                transition: opacity 0.2s;
            }}
            .copy-container:hover .copy-btn {{
                opacity: 1;
            }}
            .copy-btn:active {{
                background-color: #1F2937;
            }}
        </style>
    </head>
    <body class="bg-gray-50">
        <div id="header-placeholder"></div>
        <script src="../js/header-loader.js" defer></script>
        <main class="container mx-auto pt-20">
        <div class="container mx-auto max-w-4xl p-4 sm:p-8">
            <header class="mb-8 flex flex-wrap justify-between items-center gap-4">
                <div>
                    <h1 class="text-3xl font-bold text-gray-800">Diretório de Questões</h1>
                    <p class="text-lg text-gray-600 mt-2">Navegue pelas questões disponíveis no The Huxley.</p>
                </div>
                <div>
                    <a href="https://github.com/mestrevh/questions-the-huxley-dataset/archive/refs/heads/main.zip" 
                    target="_blank" 
                    class="bg-green-600 text-white px-3 py-2 rounded-md font-semibold hover:bg-green-700 transition-colors text-sm shadow-sm whitespace-nowrap">
                    &#x21E9; Baixar o dataset das questões
                    </a>
                </div>
            </header>
            <main>
                <div class="bg-white p-6 rounded-xl shadow-lg">
                    <div class="mb-6">
                        <label for="search-box" class="block text-sm font-medium text-gray-700 mb-1">Pesquisar por nome:</label>
                        <input type="text" id="search-box" onkeyup="filterQuestions()"
                            class="block w-full p-2 border border-gray-300 rounded-md shadow-sm focus:ring-blue-500 focus:border-blue-500"
                            placeholder="Ex: Banda, question2, ...">
                    </div>
                    
                    <h2 class="text-xl font-semibold text-gray-700 mb-4">Questões Disponíveis:</h2>
                    <ul id="question-list" class="list-disc list-inside space-y-1">
                        {list_items}
                    </ul>
                </div>
            </main>
            <footer class="text-center text-gray-500 mt-12">
                <p>Gerado automaticamente para o projeto GitHub Pages.</p>
            </footer>
        </div>
        </main>
        
        <script>
            function filterQuestions() {{
                const input = document.getElementById('search-box');
                const filter = input.value.toLowerCase();
                const ul = document.getElementById('question-list');
                const li = ul.getElementsByTagName('li');

                for (let i = 0; i < li.length; i++) {{
                    const dataTitle = li[i].getAttribute('data-title');
                    if (dataTitle.includes(filter)) {{
                        li[i].style.display = "";
                    }} else {{
                        li[i].style.display = "none";
                    }}
                }}
            }}
        </script>
    </body>
    </html>
    """

    def _create_question_page(self, question_id, card_descricao_html, card_entrada_html, card_saida_html, inputs_paths, outputs_paths, topics_str) -> str:
        options_html = '<option value="">Selecione um exemplo...</option>'
        for i in range(len(inputs_paths)):
            # Usa a constante da base do github para não espalhar strings pelo código
            input_path = self.BASE_GITHUB_PATH + str(inputs_paths[i]).replace("\\", "/")
            output_path = self.BASE_GITHUB_PATH + str(outputs_paths[i]).replace("\\", "/")

            combined_path = f"{input_path};{output_path}"

            options_html += f"""
            <option value="{combined_path}">
                Exemplo {i + 1}
            </option>
            """

        topics_html = ""
        if topics_str:
            topics_list = [t.strip() for t in topics_str.split(';') if t.strip()]
            for topic in topics_list:
                topics_html += f'<span class="ml-2 bg-gray-200 text-gray-700 px-2 py-0.5 rounded-full text-xs font-medium">{topic}</span>'

        return f"""
    <!DOCTYPE html>
    <html lang="pt-br">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Questão {question_id} - TCC</title>
        <script src="https://cdn.tailwindcss.com"></script>
        <link href="https://fonts.googleapis.com/css2?family=Inter:wght@400;500;600;700&display=swap" rel="stylesheet">
        <script src="https://cdn.tailwindcss.com?plugins=typography"></script>
        <style>
            body {{ font-family: 'Inter', sans-serif; }}
            pre {{
                white-space: pre-wrap;   
                word-wrap: break-word;   
            }}
            .copy-container {{
                position: relative;
            }}
            .copy-btn {{
                position: absolute;
                top: 0.5rem;
                right: 0.5rem;
                background-color: #4B5563; 
                color: white;
                padding: 0.25rem 0.5rem;
                border-radius: 0.375rem; 
                font-size: 0.75rem; 
                font-weight: 500; 
                opacity: 0;
                cursor: pointer;
                transition: opacity 0.2s;
            }}
            .copy-container:hover .copy-btn {{
                opacity: 1;
            }}
            .copy-btn:active {{
                background-color: #1F2937; 
            }}
        </style>
    </head>
    <body class="bg-gray-100">
        <div class="container mx-auto max-w-4xl p-4 sm:p-8">
            <header class="mb-6 flex justify-between items-center">
                <h1 class="text-2xl font-bold text-gray-800">Detalhes da questão {question_id}</h1>
                <a href="index.html" class="text-blue-600 hover:text-blue-800 hover:underline">&larr; Voltar para a lista</a>
            </header>
            
            <main class="space-y-6">
                <div class="bg-white p-6 rounded-xl shadow-lg">
                    <div class="flex flex-wrap justify-between items-center mb-4 gap-2">
                        <h2 class="text-xl font-semibold text-gray-700">Tópicos do problema</h2>
                        <div class="flex flex-wrap justify-end gap-2">{topics_html}</div>
                    </div>
                    <div class="prose max-w-none p-4 border border-gray-200 rounded-lg bg-gray-50">{card_descricao_html}</div>
                </div>

                <div class="bg-white p-6 rounded-xl shadow-lg">
                    <h2 class="text-xl font-semibold text-gray-700 mb-4">Formato da Entrada</h2>
                    <div class="prose max-w-none p-4 border border-gray-200 rounded-lg bg-gray-50">{card_entrada_html}</div>
                </div>

                <div class="bg-white p-6 rounded-xl shadow-lg">
                    <h2 class="text-xl font-semibold text-gray-700 mb-4">Formato da Saída</h2>
                    <div class="prose max-w-none p-4 border border-gray-200 rounded-lg bg-gray-50">{card_saida_html}</div>
                </div>

                <div class="bg-white p-6 rounded-xl shadow-lg">
                    <h2 class="text-xl font-semibold text-gray-700 mb-4">Exemplos de Entrada e Saída</h2>
                    
                    <div class="mb-4 flex items-center gap-4">
                        <label for="example-select" class="text-sm font-medium text-gray-700 whitespace-nowrap">Selecione um exemplo:</label>
                        <select 
                            id="example-select" 
                            onchange="handleSelectChange(this.value)"
                            class="block w-full p-2 border border-gray-300 rounded-md shadow-sm focus:ring-blue-500 focus:border-blue-500">
                            {options_html}
                        </select>
                    </div>

                    <div class="grid grid-cols-1 md:grid-cols-2 gap-4">
                        <div>
                            <h3 class="font-semibold text-gray-700 mb-2">Entrada (Input)</h3>
                            <div class="copy-container">
                                <pre id="input-content" class="h-48 p-3 border border-gray-300 rounded-md bg-gray-50 overflow-auto">Clique em um exemplo para carregar a entrada.</pre>
                                <button id="copy-input-btn" onclick="copyToClipboard('input-content')" class="copy-btn">Copiar</button>
                            </div>
                        </div>
                        <div>
                            <h3 class="font-semibold text-gray-700 mb-2">Saída (Output)</h3>
                            <div class="copy-container">
                                <pre id="output-content" class="h-48 p-3 border border-gray-300 rounded-md bg-gray-50 overflow-auto">Clique em um exemplo para carregar a saída.</pre>
                                <button id="copy-output-btn" onclick="copyToClipboard('output-content')" class="copy-btn">Copiar</button>
                            </div>
                        </div>
                    </div>
                </div>
            </main>
            <footer class="text-center text-gray-500 mt-12">
                <p>Gerado automaticamente.</p>
            </footer>
        </div>
        
        <script>
            function handleSelectChange(selectedValue) {{
                const inputDiv = document.getElementById('input-content');
                const outputDiv = document.getElementById('output-content');
                
                if (!selectedValue) {{
                    inputDiv.textContent = 'Clique em um exemplo para carregar a entrada.';
                    outputDiv.textContent = 'Clique em um exemplo para carregar a saída.';
                    return;
                }}
                
                const [inputPath, outputPath] = selectedValue.split(';');
                loadExample(inputPath, outputPath);
            }}

            async function loadExample(inputPath, outputPath) {{
                const inputDiv = document.getElementById('input-content');
                const outputDiv = document.getElementById('output-content');
                
                inputDiv.textContent = 'Carregando...';
                outputDiv.textContent = 'Carregando...';

                try {{
                    const inputResponse = await fetch(inputPath);
                    if (!inputResponse.ok) throw new Error('Arquivo de input não encontrado.');
                    const inputText = await inputResponse.text();
                    inputDiv.textContent = inputText;

                    const outputResponse = await fetch(outputPath);
                    if (!outputResponse.ok) throw new Error('Arquivo de output não encontrado.');
                    const outputText = await outputResponse.text();
                    outputDiv.textContent = outputText;

                }} catch (error) {{
                    console.error('Erro ao carregar o exemplo:', error);
                    inputDiv.textContent = 'Erro ao carregar arquivo.';
                    outputDiv.textContent = 'Erro ao carregar arquivo.';
                }}
            }}

            function copyToClipboard(elementId) {{
                const content = document.getElementById(elementId).textContent;
                navigator.clipboard.writeText(content).then(() => {{
                    alert('Conteúdo copiado!');
                }}).catch(err => {{
                    console.error('Falha ao copiar:', err);
                }});
            }}
        </script>
    </body>
    </html>
    """