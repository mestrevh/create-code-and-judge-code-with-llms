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
    
    def __send_prompt(self, prompt: str) -> str:
        try:
            response = self.__agent.generate_content(prompt)
            return response.text
        except Exception as e:
            print(f"[GEMINI] API not response: {e}")
            return None
     
    def generate_code(self, problem: ProblemRepository) -> bool:
        init_prompt = "Análise os dados da questão abaixo: \n"
        init_prompt = problem.get_format_question_prompt()
        
        prompt = (
                    f"{init_prompt}"
                    "Você é um especialista em programação programação competitiva em C++.\n"
                    "Faça um programa em C++ para o problema abaixo.\n"
                    "Responda apenas com o código, sem comentários ou texto extra.\n"
                    "O problema está no formato de string e com tags html, modifique para entender melhor o problema\n"
                    "Os links que aparecerem tente acessar e retirar informações para ajudar na resolução.\n\n"
                    
                )
        
        code = self.__send_prompt(prompt)
        
        if code is None:
            print("[File Manager]: Não é possível criar o arquivo")
            return False
        
        #Retirando o markdown
        code = code[6:len(code)-3]
        title = f"/*\nCódigo criado pelo {self.__agent.model_name}\n"
        title += "Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)\n*/"
        code = title + code
        
        path = "database/output/code_gemini"
        file_manager.create_dir(path)
        
        if not file_manager.create_file(f"question{problem.get_id()}.cpp", path, code):
            print("[File Manager]: Não foi possível criar o arquivo")
            return False
        
        return True
    
    def evaluate_code(self, code: str, problem: ProblemRepository) -> str:
        pass