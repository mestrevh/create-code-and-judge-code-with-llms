from repositories.problem_repository import ProblemRepository
from interfaces import LLMProvider
from utils import file_manager

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
        
        