import google.generativeai as genai
from core.config import config
from interfaces.llm_provider import LLMProvider
from repositories.problem_repository import ProblemRepository
from utils.file_manager import file_manager

class GeminiService(LLMProvider):
    
    __agent = None
    
    def __init__(self):
        genai.configure(api_key=config.GEMINI_API_KEY)
        
        models = ['models/gemini-2.5-flash', 'models/gemini-2.5-pro', 'models/gemini-3-pro-preview']
        
        while True:
            print("Modelos:" + str(models))
            model = input("Escolha um modelo: ")

            if model in models:
                self.__agent = genai.GenerativeModel(model)
                break
            else:
                print("Escolha um nome que está nas opções")
    
    def __get_models_gemini(self) -> list:
        return genai.list_models()
    
    def __model_name_format_dir(self) -> str:
        model_name = self.__agent.model_name.replace('/', '-')
        model_name = model_name.replace('.', '-')
        model_name = model_name.replace('_', '-')
        
        return model_name
    
    def get_path_code(self) -> str:
        return f"database/output/code_gemini/{self.__model_name_format_dir()}"
    
    def get_path_judge(self) -> str:
        return f"database/output/judge_gemini/{self.__model_name_format_dir()}"
    
    def send_prompt(self, prompt: str) -> str:
        try:
            print(f"[GEMINI API]: Enviando prompt para o modelo: {self.__agent.model_name}")
            response = self.__agent.generate_content(prompt)
            return response.text
        except Exception as e:
            print(f"[GEMINI] API not response: {e}")
            return None
    
    def generate_code(self, problem: ProblemRepository) -> bool:
        prompt = (
                    "Você é um Grande Mestre em Programação Competitiva (estilo ICPC/Maratona) e especialista em C++ moderno.\n\n"
                    
                    "Sua tarefa é escrever uma solução altamente otimizada em C++ para o problema algorítmico fornecido abaixo.\n\n"
                    
                    "REGRAS E RESTRIÇÕES ESTRITAS:\n"
                    "1. RETORNE EXCLUSIVAMENTE CÓDIGO: Não inclua saudações, explicações, comentários fora do código ou pensamentos.\n"
                    "2. SEM MARKDOWN: Não envolva o código em blocos de markdown (não use ```cpp nem ```). Comece diretamente com '#include'.\n"
                    "3. IGNORAR HTML: O problema pode conter tags HTML. Ignore a formatação visual e foque estritamente nas regras lógicas, restrições de tempo, formato de Entrada (Input) e Saída (Output).\n"
                    "4. OTIMIZAÇÃO: Priorize complexidade de tempo O(N log N) ou O(N) sempre que possível. Inclua a otimização padrão de I/O em C++ (ios_base::sync_with_stdio(false); cin.tie(NULL);) na função main.\n"
                    "5. DADOS FALTANTES: Como você não tem acesso à internet, ignore quaisquer links externos na descrição e resolva o problema baseando-se puramente no texto fornecido.\n\n"
                    
                    "--- INÍCIO DO PROBLEMA ---\n"
                    f"{problem.get_format_question_prompt()}\n"
                    "--- FIM DO PROBLEMA ---\n"
                )
        
        return super().generate_code(problem=problem,
                                     path=self.get_path_code(),
                                     prompt=prompt,
                                     model_name=self.__agent.model_name)
    
    def evaluate_code(self, problem: ProblemRepository, path: str) -> bool:
        
        code = file_manager.read_file(path=f"{path}/question{problem.get_id()}.cpp")
        
        prompt = (
                        "Você é um Sistema Juiz Automático (Online Judge) implacável e um Engenheiro de Software Sênior especialista em C++.\n\n"
                        
                        "SUA TAREFA:\n"
                        "Realize uma análise estática rigorosa e simule mentalmente a execução do código fornecido contra os casos de teste especificados.\n\n"
                        
                        "REGRAS DE AVALIAÇÃO:\n"
                        "1. SIMULAÇÃO EXATA: Rastreie a lógica do código passo a passo. Compare a saída da sua simulação usando os dados de <input test> com o resultado esperado em <output test>. A correspondência deve ser exata (espaços, quebras de linha).\n"
                        "2. SEM ALUCINAÇÃO DE TEMPO: Como você não compila o código fisicamente, NUNCA invente tempos em milissegundos. Avalie a eficiência usando exclusivamente a Notação Big-O (Complexidade de Tempo e Espaço).\n"
                        "3. CORNER CASES: Verifique se o código lida bem com tipos de dados (ex: overflow de int para long long), limites de arrays e casos base.\n\n"
                        
                        "FORMATO DE SAÍDA OBRIGATÓRIO (Responda estritamente neste formato para ser analisado por um script):\n"
                        "VEREDITO: [Escreva apenas APROVADO ou REPROVADO]\n"
                        "COMPLEXIDADE: [Escreva o Big-O de tempo e espaço, ex: O(N) tempo, O(1) espaço]\n"
                        "FEEDBACK: [Justifique sua avaliação. Se REPROVADO, explique qual teste falhou ou qual erro de sintaxe/lógica ocorreu. Se APROVADO, comente sobre a eficiência da implementação.]\n\n"
                        
                        "--- DADOS DO PROBLEMA E CASOS DE TESTE ---\n"
                        f"{problem.get_format_question_prompt()}\n\n"
                        
                        "--- CÓDIGO SUBMETIDO PARA AVALIAÇÃO ---\n"
                        f"{code}\n"
                    )

        return super().evaluate_code(problem=problem,
                                     path=self.get_path_judge(),
                                     prompt=prompt,
                                     model_name=self.__agent.model_name)
        
    def simulation_the_huxley(self, problem: ProblemRepository, code_path: str) -> bool:
        
        code = file_manager.read_file(path=f"{code_path}/question{problem.get_id()}.cpp")

        prompt = (
                    "Você é um Sistema Juiz Automático (Online Judge) especialista em Programação Competitiva (C++).\n"
                    "Sua tarefa é simular rigorosamente a compilação e a execução do código fornecido contra os casos de teste do problema.\n\n"
                    
                    "--- CÓDIGO SUBMETIDO ---\n"
                    f"{code}\n\n"
                    
                    "--- TESTES ---\n"
                    f"{problem.get_cases_test_of_problem()}\n\n"
                    
                    "INSTRUÇÕES DE AVALIAÇÃO (Simule mentalmente os seguintes passos):\n"
                    "1. COMPILAÇÃO: Verifique se há erros de sintaxe (COMPILATION_ERROR).\n"
                    "2. EXECUÇÃO: Simule o código com as entradas `<input test>` e compare exaustivamente com os `<output test>`.\n"
                    "3. CASOS OCULTOS: Avalie mentalmente corner cases (casos extremos), limites de arrays e possíveis divisões por zero (RUNTIME_ERROR).\n"
                    "4. TEMPO DE EXECUÇÃO: Estime o tempo de execução real do código em segundos (ex: 0.015), considerando a complexidade do algoritmo e o tamanho máximo das entradas (assumindo que o C++ executa ~10^8 operações por segundo). Se exceder o tempo limite do problema, classifique como TIME_LIMIT_EXCEEDED.\n\n"
                    
                    "VEREDICTOS PERMITIDOS (Escolha estritamente um):\n"
                    "- CORRECT (Passou em tudo perfeitamente)\n"
                    "- WRONG_ANSWER (A saída simulada divergiu da esperada)\n"
                    "- TIME_LIMIT_EXCEEDED (Passou do tempo limite de execução estimado)\n"
                    "- RUNTIME_ERROR (Falha de segmentação, erro de memória)\n"
                    "- COMPILATION_ERROR (Erro de sintaxe C++)\n"
                    "- EMPTY_ANSWER (Não gerou saída alguma)\n\n"
                    
                    "FORMATO DE SAÍDA OBRIGATÓRIO:\n"
                    "Não escreva textos introdutórios ou explicações fora do formato. Retorne EXCLUSIVAMENTE um objeto JSON válido contendo a sua análise, sem markdown.\n\n"
                    "{\n"
                    '  "tempo_judger": 0.000\n'
                    '  "status_judger": "VEREDICTO_AQUI",\n'
                    '  "total_acertos_judger": 0,\n'
                    '  "total_erros_judger": 0,\n'
                    '  "total_casos_teste_judger": 0\n'
                    "}"
                )
        
        return super().simulation_the_huxley(problem=problem,
                                             code_path=code_path,
                                             path="database/output/json",
                                             prompt=prompt,
                                             model_name=self.__agent.model_name,
                                             code=code)