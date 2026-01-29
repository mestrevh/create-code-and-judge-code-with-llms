from abc import ABC, abstractmethod

class DatabaseInterface(ABC):
    @abstractmethod
    def get_questions_the_huxley(self, casesTest: bool = False):
        pass
    
    @abstractmethod
    def get_question_database(self, id: int):
        pass