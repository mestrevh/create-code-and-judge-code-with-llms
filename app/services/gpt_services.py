from core import config
from interfaces import LLMProvider
from repositories import ProblemRepository
from utils import file_manager
from openai import OpenAI

class GPTService(LLMProvider):
    
    __agent: any = None
    __input_model: str = None
    
    def __init__(self):
        self.__agent = OpenAI(api_key=config.GPT_API_KEY)
        
        models = []
        
        response = self.__agent.models.list()
        
        for model in response.data:
            name = model.id.lower()
            if name.startswith("gpt-"):
                models.append(model.id)
        
        while True:
            print("Modelos:" + str(models))
            model_name = input("Escolha um modelo: ")

            if model_name in models:
                self.__input_model = model_name
                break
            else:
                print("Escolha um nome que está nas opções")
            
        
        
    
    def get_path_code(self) -> str:
        return "database/output/code_gpt"
    
    def get_path_judge(self) -> str:
        return "database/output/judge_gpt"
    
    def send_prompt(self, prompt: str) -> str:
        try:
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
                    "Você é um especialista em programação competitiva em C++.\n\n"

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
                    "Você é um avaliador especialista em programação competitiva em C++.\n\n"
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