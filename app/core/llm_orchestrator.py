from repositories.problem_repository import ProblemRepository
from interfaces.llm_provider import LLMProvider
from utils.file_manager import file_manager
from utils.request_web import request_web

class LLMOrchestrator:
    
    __coder: LLMProvider
    __judger: LLMProvider
    
    def __init__(self,
                 coder: LLMProvider,
                 judger: LLMProvider
                 ):
        
        self.__coder = coder
        self.__judger = judger
    
    def create_and_judge_code(self, problem: ProblemRepository) -> bool:
        path = "database"
        file_manager.create_dir(path)
        path += "/output"
        file_manager.create_dir(path)
        
        if not self.__coder.generate_code(problem):
            print("Não foi possível criar o código...")
            return False
        
        print(f"Código questão {problem.get_id()} gerado com sucesso!")
        
        if not self.__judger.evaluate_code(problem=problem, path=self.__coder.get_path_code()):
            print(f"Não foi possível criar o judge{problem.get_id()}.md...")
            return False
        
        print(f"judge{problem.get_id()}.md gerado com sucesso!")
        
        return True
    
    def simulation_the_huxley_with_llm(self, problem: ProblemRepository) -> bool:
        
        if request_web.get(link=f"https://www.thehuxley.com/api/v1/problems/{problem.get_id()}") is None:
            return False
        
        path = "database"
        file_manager.create_dir(path)
        path += "/output"
        file_manager.create_dir(path)
        
        if not self.__coder.generate_code(problem):
            print("Não foi possível criar o código...")
            return False
        
        print(f"Código questão {problem.get_id()} gerado com sucesso!")
        return True
        if not self.__judger.simulation_the_huxley(problem=problem, code_path=self.__coder.get_path_code()):
            print(f"Não foi possível criar a instancia da questão {problem.get_id()}...")
            return False
        
        print(f"simulation_the_huxley_model.json gerado com sucesso!")
        
        return True
        
        