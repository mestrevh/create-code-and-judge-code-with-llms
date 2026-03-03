import google.generativeai as genai
from core import config
from interfaces import LLMProvider
from repositories import ProblemRepository
from utils import file_manager

class GeminiService(LLMProvider):
    
    __agent = None
    
    def __init__(self):
        genai.configure(api_key=config.GEMINI_API_KEY)
        
        models = []
        
        for model in genai.list_models():
            if 'generateContent' in model.supported_generation_methods:
                models.append(model.name)
        
        model = "models/"
        
        while True:
            print("Modelos:" + str(models))
            model = input("Escolha um modelo: ")

            if model in models:
                break
            else:
                print("Escolha um nome que está nas opções")
            
        self.__agent = genai.GenerativeModel(model)
    
    def __get_path_code(self) -> str:
        return "database/output/code_gemini"
    
    def __get_path_judge(self) -> str:
        return "database/output/judge_gemini"
    
    def send_prompt(self, prompt: str) -> str:
        try:
            response = self.__agent.generate_content(prompt)
            return response.text
        except Exception as e:
            print(f"[GEMINI] API not response: {e}")
            return None
     
    def generate_code(self, problem: ProblemRepository) -> bool:
        prompt = (
                    "Análise os dados da questão abaixo: \n"
                    f"{problem.get_format_question_prompt()}\n"
                    "Você é um especialista em programação programação competitiva em C++.\n"
                    "Faça um programa em C++ para o problema abaixo.\n"
                    "Responda apenas com o código, sem comentários ou texto extra.\n"
                    "O problema está no formato de string e com tags html, modifique para entender melhor o problema\n"
                    "Os links que aparecerem tente acessar e retirar informações para ajudar na resolução.\n\n"
                )
        
        return super().generate_code(problem=problem,
                                     path=self.__get_path_code(),
                                     prompt=prompt,
                                     model_name=self.__agent.model_name)
    
    def evaluate_code(self, problem: ProblemRepository) -> bool:
        
        code = file_manager.read_file(path=f"{self.__get_path_code()}/question{problem.get_id()}.cpp")
        
        prompt = (
                    "Análise os dados da questão abaixo: \n"
                    f"{problem.get_format_question_prompt()}\n"
                    "Você é um avaliador de código experiente em C++.\n"
                    f"Avalie o seguinte código:\n\n{code}\n\n"
                    "Execute esse código em C++ com <test cases></test cases>.\n"
                    "Veja que <input test></input test> tem um <output test></output test> respectivo.\n"
                    "Saída deste prompt deve ter essa sequência:\n\n"
                    "1. Correto, se acertar todos os <test cases></test cases>;\n"
                    "2. Tempo de execução do código\n"
                    "3. Avaliação do código - o código está implementado de forma eficiente e resolve o problema?"
                  )
        
        
        return super().evaluate_code(problem=problem,
                                     path=self.__get_path_judge(),
                                     prompt=prompt,
                                     model_name=self.__agent.model_name)