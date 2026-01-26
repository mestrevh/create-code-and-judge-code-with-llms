from repositories import database_repository

class DatabaseServices:
    
    def create_database(self, cases_test):
        database_repository.get_questions_the_huxley(link="https://www.thehuxley.com/api/v1/problems", cases_test=cases_test)