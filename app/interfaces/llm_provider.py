from abc import ABC, abstractmethod
from repositories.problem_repository import ProblemRepository
from utils import file_manager

class LLMProvider(ABC):
    
    @abstractmethod
    def send_prompt(self, prompt: str) -> str:
        pass
    
    @abstractmethod
    def get_path_code(self) -> str:
        pass
    
    @abstractmethod
    def get_path_judge(self) -> str:
        pass
    
    @abstractmethod
    def generate_code(self, problem: ProblemRepository, path: str, prompt: any, model_name: str) -> bool:
        
        code = self.send_prompt(prompt)
        
        if code is None:
            print("[File Manager]: Não é possível criar o arquivo")
            return False
        
        title = f"/*\nCódigo criado pelo {model_name}\n"
        title += "Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)*/\n"
        code = title + code
        
        file_manager.create_dir(path)
        
        if not file_manager.create_file(f"question{problem.get_id()}.cpp", path, code):
            print("[File Manager]: Não foi possível criar o arquivo")
            return False
        
        return True
    
    @abstractmethod
    def evaluate_code(self, problem: ProblemRepository, path:str, prompt: any, model_name: str) -> bool:
        
        response = self.send_prompt(prompt=prompt)
        
        if response is None:
            print("[File Manager]: Não é possível criar o arquivo")
            return False
        
        file_manager.create_dir(path)
        
        response = f"# Modelo do judge: {model_name}\n\n" + response
        
        if not file_manager.create_file(f"judge{problem.get_id()}.md", path, response):
            print("[File Manager]: Não foi possível criar o arquivo")
            return False
        
        return True