from core.config import config
from interfaces.llm_provider import LLMProvider
from repositories.problem_repository import ProblemRepository
from utils.file_manager import file_manager
from openai import OpenAI

class GPTService(LLMProvider):
    
    __agent: any = None
    __input_model: str = None
    
    def __init__(self):
        self.__agent = OpenAI(api_key=config.GPT_API_KEY)
        
        models = ['gpt-5.4-nano', 'gpt-5.4', 'gpt-4o-mini']
        
        while True:
            print("Modelos:" + str(models))
            model_name = input("Escolha um modelo: ")

            if model_name in models:
                self.__input_model = model_name
                break
            else:
                print("Escolha um nome que está nas opções")
            
        def __get_models_gpt(self) -> list:
            return self.__agent.models.list()
    
    def __model_name_format_dir(self) -> str:
        model_name = self.__input_model.replace('/', '-')
        model_name = model_name.replace('.', '-')
        model_name = model_name.replace('_', '-')
        
        return model_name
    
    def get_path_code(self) -> str:
        return f"database/output/code_gpt/{self.__model_name_format_dir()}"
    
    def get_path_judge(self) -> str:
        return f"database/output/judge_gpt/{self.__model_name_format_dir()}"
    
    def send_prompt(self, prompt: str) -> str:
        try:
            print(f"[GPT API]: Enviando prompt para o modelo: {self.__input_model}")
            response = self.__agent.responses.create(
                    model=self.__input_model,
                    input=prompt
                )
            
            return response.output_text
        except Exception as e:
            print(f"[GPT] API not response: {e}")
            return None
     
    def generate_code(self, problem: ProblemRepository) -> bool:
        prompt = (
                    "Persona: Você é um especialista em programação competitiva em C++.\n\n"

                    "Abaixo está a descrição de um problema. O texto pode conter HTML.\n"
                    "Interprete corretamente o conteúdo ignorando todas as tags HTML.\n"
                    "Extraia mentalmente apenas:\n"
                    "- Descrição\n"
                    "- Entrada\n"
                    "- Saída\n"
                    "- Restrições\n"
                    "- Exemplos\n\n"

                    "========== PROBLEMA ==========\n"
                    f"{problem.get_format_question_prompt()}\n"
                    "========== FIM DO PROBLEMA ==========\n\n"

                    "Resolva o problema implementando um programa em C++.\n\n"

                    "Regras obrigatórias da resposta:\n"
                    "1) Retorne somente o código C++ completo, sem markdown.\n"
                    "2) Não inclua comentários.\n"
                    "3) Não inclua explicações.\n"
                    "4) Não inclua texto fora do código.\n"
                    "5) O código deve compilar em C++17.\n"
                )
        
        return super().generate_code(problem=problem,
                                     path=self.get_path_code(),
                                     prompt=prompt,
                                     model_name=self.__input_model)
    
    def evaluate_code(self, problem: ProblemRepository, path: str) -> bool:
        
        code = file_manager.read_file(path=f"{path}/question{problem.get_id()}.cpp")
        
        prompt = (
                    "Persona: Você é um avaliador especialista em programação competitiva em C++.\n\n"
                    "Sua tarefa é avaliar um código com base em um problema e seus casos de teste.\n\n"

                    "========== PROBLEMA ==========\n"
                    f"{problem.get_format_question_prompt()}\n"
                    "========== FIM DO PROBLEMA ==========\n\n"

                    "========== CÓDIGO ==========\n"
                    f"{code}\n"
                    "========== FIM DO CÓDIGO ==========\n\n"

                    "========== CASOS DE TESTE ==========\n"
                    "<test cases>\n"
                    "Cada <input test> possui um <output test> correspondente.\n"
                    "Execute logicamente o código considerando cada entrada e compare com a saída esperada.\n"
                    "</test cases>\n"
                    "========== FIM DOS CASOS ==========\n\n"

                    "Critérios de avaliação:\n"
                    "1) Se todos os testes produzirem exatamente a saída esperada, considere 'Correto'.\n"
                    "2) Caso qualquer teste falhe, considere 'Incorreto'.\n"
                    "3) Estime o tempo de execução com base na complexidade assintótica.\n"
                    "4) Avalie se o código é eficiente e adequado às restrições do problema.\n\n"

                    "Formato obrigatório da resposta (exatamente nesta ordem):\n"
                    "1. Status: Correto ou Incorreto\n"
                    "2. Tempo estimado: <complexidade ou estimativa>\n"
                    "3. Avaliação: <breve análise da eficiência e implementação>\n"
                )
        
        
        return super().evaluate_code(problem=problem,
                                     path=self.get_path_judge(),
                                     prompt=prompt,
                                     model_name=self.__input_model)
    
    def simulation_the_huxley(self, problem: ProblemRepository, code_path: str) -> bool:
        
        print(f"{code_path}/question{problem.get_id()}.cpp")
        code = file_manager.read_file(path=f"{code_path}/question{problem.get_id()}.cpp")
        
        prompt = (
                    "Persona: Você é um juiz automático especializado em programação competitiva em C++.\n\n"

                    "TAREFA:\n"
                    "1) Analise o código fornecido.\n"
                    "2) Verifique se compila logicamente.\n"
                    "3) Gere internamente casos de teste relevantes com base no problema.\n"
                    "4) Execute logicamente o código contra esses testes.\n"
                    "5) Compare com a saída esperada.\n\n"

                    "========== CASOS DE TESTES ==========\n"
                    f"{problem.get_format_question_prompt()}\n"
                    "========== FIM CASOS DE TESTES ==========\n\n"

                    "========== CÓDIGO ==========\n"
                    f"{code}\n"
                    "========== FIM CÓDIGO ==========\n\n"

                    "CLASSIFICAÇÕES POSSÍVEIS:\n"
                    "CORRECT\n"
                    "WRONG_ANSWER\n"
                    "TIME_LIMIT_EXCEEDED\n"
                    "RUNTIME_ERROR\n"
                    "COMPILATION_ERROR\n"
                    "EMPTY_ANSWER\n\n"

                    "Responda APENAS no seguinte formato JSON válido:\n"
                    "{\n"
                    '  "tempo_juder": "estimativa de tempo (número com casas decimais)",\n'
                    '  "status_judger": "uma das classificações acima",\n'
                    '  "total_acertos_judger": número inteiro,\n'
                    '  "total_erros_judger": número inteiro,\n'
                    '  "total_testes_judger": número inteiro\n'
                    "}\n\n"

                    "Regras obrigatórias:\n"
                    "- Não inclua explicações.\n"
                    "- Não inclua comentários.\n"
                    "- Não inclua texto antes ou depois do JSON.\n"
                    "- Retorne o JSON, sem markdown.\n"
                )
        
        return super().simulation_the_huxley(problem=problem,
                                             code_path=code_path,
                                             path="database/output/json",
                                             prompt=prompt,
                                             model_name=self.__input_model,
                                             code=code)