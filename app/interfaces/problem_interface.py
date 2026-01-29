from abc import ABC, abstractmethod

class ProblemInterface(ABC):
    @abstractmethod
    def get_format_question_prompt(self):
        pass