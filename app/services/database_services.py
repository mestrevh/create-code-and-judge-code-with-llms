from repositories import database_repository

class DatabaseServices:
    
    def create_database(self, cases_test: bool):
        database_repository.get_questions_the_huxley(link="https://www.thehuxley.com/api/v1/problems", cases_test=cases_test)
        
    def build_questions_id(self):
        database_repository.update_questions_id()
        
    def get_problems(self):
        return database_repository.get_questions_id()
        
    def get_problem(self, id:int):
        problem = database_repository.get_question_database(id)
        
        return problem