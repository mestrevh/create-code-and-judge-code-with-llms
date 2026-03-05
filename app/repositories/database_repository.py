from interfaces.database_interface import DatabaseInterface
from models.database_model import DatabaseModel
from utils.request_web import request_web
from utils.file_manager import file_manager
from typing import List
from repositories.problem_repository import ProblemRepository
from core.config import config


class DatabaseRepository(DatabaseInterface):
        
    def __init__(self, DatabaseModel: DatabaseModel):
        self.data = DatabaseModel
        self.data.questions_id = self.__set_questions_id()
    
    def __set_questions_id(self) -> List[int]:
        questions_id = []
        
        if file_manager.dir_exist("database/questions"):
            count = 0
            id = 0
            
            while count != 1000:
                if file_manager.dir_exist(f"database/questions/question{id}"):
                    count = 0
                    questions_id.append(id)
                else:
                    count += 1
                    
                id += 1
                    
        return questions_id
    
    def update_questions_id(self):
        self.data.questions_id = self.__set_questions_id()
        
    def get_questions_id(self) -> List[int]:
        return self.data.questions_id
    
    def __post_send_oracle_the_huxley(self, id: int, input: str) -> str:
        link = f"https://www.thehuxley.com/api/v1/problems/{id}/oracle"

        headers = {
            "Accept": "application/json, text/plain, */*",
            "Content-Type": "application/json;charset=utf-8",  # Essencial para enviar JSON
            "Authorization": "Bearer " + config.TOKEN_THE_HUXLEY,
            "Origin": "https://www.thehuxley.com",
            "Referer": f"https://www.thehuxley.com/problem/{id}/oracle",
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:143.0) Gecko/20100101 Firefox/143.0",
        }

        payload = {
            "input": input
        }
        response = request_web.post(link, headers=headers, json=payload)
        print(f"Oráculo para o problema {id} consultado com sucesso!")
        
        if response is not None:

            hash = response.json().get('hash')
            link_oracle = f"https://www.thehuxley.com/api/v1/problems/{id}/oracle/{hash}"
            
            data = request_web.get(link_oracle, headers=headers)
                
            if data is not None:
                return data.get('output')

        return None
        
    def __get_question_with_token_the_huxley(self, id: int) -> list:
        
        examples = []
        
        code = "case = [input()]\n"
        code += "try:\n"
        code += "    while True:\n"
        code += "        case.append(input())\n"
        code += "except EOFError:\n"
        code += "    raise Exception(''.join([str(x) + '\\n' for x in case]))\n"
        
        if request_web.post_code_the_huxley(id, code, "py") is not None:
            submissions = request_web.get_last_submission_the_huxley(id)

            if submissions["testCaseEvaluations"] != None:
                for submission in submissions["testCaseEvaluations"]:
                    
                    if submission["errorMsg"] == None:
                        continue
                    
                    case_test = {}
                    
                    init = submission["errorMsg"].find("\nException:") + len("\nException:")
                    input = submission["errorMsg"][init + 1 : len(submission["errorMsg"]) - 2]
                    
                    
                    case_test["input"]  = input
                    case_test["output"] = self.__post_send_oracle_the_huxley(id, input)
                    
                    examples.append(case_test)
        
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
                        if file_manager.dir_exist(path + "/inputs") == False:
                            file_manager.create_dir(path + "/inputs")
                        
                        file_manager.create_file(f"in{i}.txt", path + "/inputs", cases_test[i]["input"])
                    
                    if cases_test[i]["output"] is not None:
                        if file_manager.dir_exist(path + "/outputs") == False:
                            file_manager.create_dir(path + "/outputs")
                        
                        file_manager.create_file(f"out{i}.txt", path + "/outputs", cases_test[i]["output"])
            else:
                print(f"Questão {id} foi criada (não possui) entradas e saída!")
                
            print(f"Questão {id} criado com sucesso!")
            return True
        else:
            return False
            
    
    def get_questions_the_huxley(self, link:str = "", cases_test:bool = False) -> bool:
        
        path = "database"
        file_manager.create_dir(path)
        path += "/questions"
        file_manager.create_dir(path)
        
        count = 0
        id = 0
        while count != 1000:
            response = request_web.get(link + "/" + str(id))
            
            if response is None:
                id += 1
                count += 1
                continue
            
            cases = None
            if cases_test:
                cases = self.__get_question_with_token_the_huxley(id=id)
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
            
            id += 1
                    
        return True
    
    def get_question_database(self, id:int) -> ProblemRepository:
        problem = ProblemRepository(id)
        return problem
    
database_repository = DatabaseRepository(DatabaseModel())