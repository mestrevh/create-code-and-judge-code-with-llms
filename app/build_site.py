import pandas as pd
from pathlib import Path
import re
import html # Importar para escapar caracteres, se necessário

def create_index_page(question_links):
    """Cria a página HTML principal (index.html) com a lista de links."""
    list_items = ""
    for q_id, q_path in question_links.items():
        list_items += f'<li class="mb-2"><a href="docs/{q_path.name}" class="text-blue-600 hover:text-blue-800 hover:underline">{q_path.parent.name.capitalize()} (ID: {q_id})</a></li>\n'

    return f"""
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Lista de Questões - TCC</title>
    <script src="https://cdn.tailwindcss.com"></script>
    <link href="https://fonts.googleapis.com/css2?family=Inter:wght@400;500;600;700&display=swap" rel="stylesheet">
    <style> body {{ font-family: 'Inter', sans-serif; }} </style>
</head>
<body class="bg-gray-50">
    <div class="container mx-auto max-w-4xl p-4 sm:p-8">
        <header class="mb-8">
            <h1 class="text-3xl font-bold text-gray-800">Diretório de Questões</h1>
            <p class="text-lg text-gray-600 mt-2">Navegue pelas questões disponíveis no projeto.</p>
        </header>
        <main>
            <div class="bg-white p-6 rounded-xl shadow-lg">
                <h2 class="text-xl font-semibold text-gray-700 mb-4">Questões Disponíveis:</h2>
                <ul class="list-disc list-inside space-y-1">
                    {list_items}
                </ul>
            </div>
        </main>
        <footer class="text-center text-gray-500 mt-12">
            <p>Gerado automaticamente para o projeto GitHub Pages.</p>
        </footer>
    </div>
</body>
</html>
"""

def create_question_page(question_id, problem_text):
    """
    Cria a página HTML para uma questão específica, 
    renderizando as tags HTML presentes no problem.txt.
    """
    # Insere o conteúdo diretamente, permitindo que o navegador interprete as tags.
    # Usamos a classe 'prose' do Tailwind Typography para estilizar o conteúdo.
    problem_html = f'<div class="prose max-w-none p-4 border border-gray-200 rounded-lg bg-gray-50">{problem_text}</div>'
    
    return f"""
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Questão {question_id} - TCC</title>
    <script src="https://cdn.tailwindcss.com"></script>
    <link href="https://fonts.googleapis.com/css2?family=Inter:wght@400;500;600;700&display=swap" rel="stylesheet">
    <!-- Adiciona suporte para estilos de prosa (formatacao de texto) do Tailwind -->
    <script src="https://cdn.tailwindcss.com?plugins=typography"></script> 
    <style> body {{ font-family: 'Inter', sans-serif; }} </style>
</head>
<body class="bg-gray-100">
    <div class="container mx-auto max-w-4xl p-4 sm:p-8">
        <header class="mb-6 flex justify-between items-center">
            <h1 class="text-2xl font-bold text-gray-800">Detalhes da Questão {question_id}</h1>
            <a href="index.html" class="text-blue-600 hover:text-blue-800 hover:underline">&larr; Voltar para a lista</a>
        </header>
        <main>
            <div class="bg-white p-6 rounded-xl shadow-lg">
                <h2 class="text-xl font-semibold text-gray-700 mb-4">Descrição do Problema (problem.txt)</h2>
                {problem_html} 
            </div>
        </main>
        <footer class="text-center text-gray-500 mt-12">
            <p>Gerado automaticamente.</p>
        </footer>
    </div>
</body>
</html>
"""

def main():
    script_dir = Path(__file__).parent
    base_dir = script_dir.parent
    questions_dir = base_dir / "app" / "questions"
    output_dir = base_dir / "docs"
    output_dir.mkdir(exist_ok=True)
    question_links = {}
    print("Iniciando a geração do site...")
    question_pattern = re.compile(r'^question(\d+)$')
    if not questions_dir.is_dir():
        print(f"ERRO: O diretório '{questions_dir}' não foi encontrado.")
        return
    for item in questions_dir.iterdir():
        if item.is_dir():
            match = question_pattern.match(item.name)
            if match:
                question_id = match.group(1)
                problem_file = item / "problem.txt"
                if problem_file.is_file():
                    print(f"  Processando {item.name}...")
                    try:
                        problem_text = problem_file.read_text(encoding='utf-8')
                        question_html_content = create_question_page(question_id, problem_text)
                        question_html_path = output_dir / f"{item.name}.html"
                        question_html_path.write_text(question_html_content, encoding='utf-8')
                        question_links[int(question_id)] = question_html_path
                    except Exception as e:
                        print(f"    ERRO ao processar {item.name}: {e}")
                else:
                    print(f"  AVISO: {item.name} não contém um arquivo 'problem.txt'. Pulando.")
    if question_links:
        sorted_links = dict(sorted(question_links.items()))
        index_html_content = create_index_page(sorted_links)
        index_html_path = base_dir / "index.html"
        index_html_path.write_text(index_html_content, encoding='utf-8')
        print(f"\nPágina principal 'index.html' gerada com sucesso em '{output_dir}'.")
    else:
        print("\nNenhuma pasta de questão válida encontrada para gerar o índice.")
    print("Geração do site finalizada.")

if __name__ == "__main__":
    main()

