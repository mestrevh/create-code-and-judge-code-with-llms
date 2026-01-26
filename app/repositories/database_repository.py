from interfaces import DatabaseInterface
from models import DatabaseModel, database_model
from utils import request_web, file_manager
from pathlib import Path

class DatabaseRepository(DatabaseInterface):
    
    def __init__(self, DatabaseModel: DatabaseModel):
        self.data = DatabaseModel
    
    def __get_question_with_token_the_huxley() -> list:
        
        examples = []
        
        return examples
    
    def __create_question(self, data: dict, path: str, id: int, cases_test: list) -> bool:
        if len(data['choices']) == 0 and data['baseLanguage'] == None:
            
            problem = f"Título: {data["name"]}\n"
            
            problem += "Topicos do problema: "
            for value in data['topics']:
                problem += value["name"] + "; "
            problem += "\n"
            
            problem += f"Tempo limite de execução: {data["timeLimit"]} segundo(s)\n"
            problem += f"Descrição: {data["description"]}\n"
            problem += f"Formato da entrada: {data["inputFormat"]}\n"
            problem += f"Formato da saída: {data["outputFormat"]}\n"

            # criando o arquivo
            path = path + f"/question{id}"
            file_manager.create_dir(path)
            
            file_manager.create_file("problem.txt", path, problem)

            if len(cases_test) > 0:
                
                for i in range(len(cases_test)):
                    if cases_test[i]["input"] is not None:
                        if file_manager.dir_is_exist(path + "/inputs") == False:
                            file_manager.create_dir(path + "/inputs")
                        
                        file_manager.create_file(f"in{i}.txt", path + "/inputs", cases_test[i]["input"])
                    
                    if cases_test[i]["output"] is not None:
                        if file_manager.dir_is_exist(path + "/outputs") == False:
                            file_manager.create_dir(path + "/outputs")
                        
                        file_manager.create_file(f"out{i}.txt", path + "/outputs", cases_test[i]["output"])
            
            print(f"Questão {id} criado com sucesso!")
            return True
        else:
            return False
            
    
    def get_questions_the_huxley(self, link:str = "", cases_test:bool = False) -> bool:
        
        path = "database"
        file_manager.create_dir(path)
        
        count = 0
        id = 0
        while count != 1000:
            id += 1
            response = request_web.get(link + "/" + str(id))
            
            cases = None
            if cases_test:
                cases = self.__get_question_with_token_the_huxley()
            else:
                cases = request_web.get(link + "/" + str(id) + "/examples")
            
            if response is not None:
                if self.__create_question(response, path, id, cases):
                    count = 0
                else:
                    print(f"Questão {id} não é para produzir código")
            else:
                count += 1
                print(f"Questão {id} não está disponível")
                    
        return True
    
database_repository = DatabaseRepository(database_model)