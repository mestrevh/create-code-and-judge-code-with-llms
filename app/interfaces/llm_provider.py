from abc import ABC, abstractmethod
from repositories.problem_repository import ProblemRepository

class LLMProvider(ABC):
    @abstractmethod
    def generate_code(self, problem: ProblemRepository) -> bool:
        pass
    
    @abstractmethod
    def evaluate_code(self, code: str, problem: ProblemRepository) -> str:
        pass