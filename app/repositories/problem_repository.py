from interfaces.problem_interface import ProblemInterface
from models.problem_model import ProblemModel
from utils.file_manager import file_manager
import json

class ProblemRepository (ProblemInterface):
    
    __problem: ProblemModel = None
    
    def __init__(self, id: int):
        self.set_problem_json(id)
        
    def get_id(self) -> int:
        return self.__problem.id
    
    def problem_is_exist(self) -> bool:
        return self.__problem is not None
    
    def set_problem(self, id: int):
        
        path = f"database/questions/question{id}"
        if file_manager.dir_exist(path):
            text = file_manager.read_file(path + "/problem.txt")
            
            if text is not None:
                return None
            
            title = text.split("Título: ")[1].split("Topicos do problema: ")[0]
            topics = text.split("Topicos do problema: ")[1].split("Tempo limite de execução: ")[0]
            
            if topics is not None:
                topics = topics.split("; ")[:-1]
            
            time_limit = text.split("Tempo limite de execução: ")[1].split("Descrição: ")[0]
            description = text.split("Descrição: ")[1].split("Formato da entrada: ")[0]
            input_format = text.split("Formato da entrada: ")[1].split("Formato da saída: ")[0]
            output_format = text.split("Formato da saída: ")[1]
            
            cases_test = []
            i = 0
            
            while True:
                case_test = {}
                
                input_path = path + f"/inputs/in{i}.txt"
                output_path = path + f"/outputs/out{i}.txt"
                
                if file_manager.file_exist(input_path):
                    case_test["input"] = file_manager.read_file(input_path)
                
                if file_manager.file_exist(output_path):
                    case_test["output"] = file_manager.read_file(output_path)
                
                if not case_test:
                    break
                
                i += 1
                cases_test.append(case_test)
            
            self.__problem = ProblemModel(id=id,
                                          title=title,
                                          descrition=description,
                                          topics=topics,
                                          time_limit=time_limit,
                                          input_format=input_format,
                                          output_format=output_format,
                                          cases_test=cases_test)
    
    def set_problem_json(self, id: int):
        
        path = f"database/questions/question{id}"
        if file_manager.dir_exist(path):
            text = file_manager.read_file(path + "/problem.json")
            
            try:
                problem_json = json.loads(text)
            except json.JSONDecodeError as e:
                print(f"[SET PROBLEM JSON]: O arquivo não contém um JSON válido. Detalhes: {e}")
                return
            
            cases_test = []
            i = 0
            
            while True:
                case_test = {}
                
                input_path = path + f"/inputs/in{i}.txt"
                output_path = path + f"/outputs/out{i}.txt"
                
                if file_manager.file_exist(input_path):
                    case_test["input"] = file_manager.read_file(input_path)
                
                if file_manager.file_exist(output_path):
                    case_test["output"] = file_manager.read_file(output_path)
                
                if not case_test:
                    break
                
                i += 1
                cases_test.append(case_test)
            
            self.__problem = ProblemModel(id=id,
                                          title=problem_json["title"],
                                          descrition=problem_json["descrition"],
                                          topics=problem_json["topics"],
                                          time_limit=problem_json["time_limit"],
                                          input_format=problem_json["format_input"],
                                          output_format=problem_json["format_output"],
                                          cases_test=cases_test)
            
    def print_problem(self):
        
        if self.__problem is not None:    
            print("Título:", self.__problem.title)
            print("Topicos do problema:", self.__problem.topics)
            print("Descrição:", self.__problem.description)
            print("Formato de entrada:", self.__problem.input_format)
            print("Formato de saída:", self.__problem.output_format)
            print(self.get_cases_test_of_problem())

    def get_cases_test_of_problem(self):
        
        output = "<test cases>\n"
        for i in range(len(self.__problem.cases_test)):
            output += f"<test {i}>\n"
            
            if self.__problem.cases_test[i].get("input") is not None:
                output += "<input test>\n"
                output += self.__problem.cases_test[i]["input"]
                output += "</input test>\n"
            
            if self.__problem.cases_test[i].get("output") is not None:
                output += "<output test>\n"
                output += self.__problem.cases_test[i]["output"]
                output += "</output teste>\n"
            
            output += f"</test {i}>\n"
            
        output += "</test cases>"
        return output
    
    def get_format_question_prompt(self):
        output = "<title>\n"
        output += self.__problem.title
        output += "</title>\n"
        
        output += "<topics>\n"
        for i in range(len(self.__problem.topics)):
            output += f"<t{i}>{self.__problem.topics[i]}</t{i}>\n"
        output += "</topics>\n"
        
        output += "<time limit>\n"
        output += f"{self.__problem.time_limit}"
        output += "</time limit>\n"
        
        output += "<time limit>\n"
        output += f"{self.__problem.time_limit}"
        output += "</time limit>\n"
        
        output += "<descrition>\n"
        output += f"{self.__problem.descrition}"
        output += "</descrition>\n"
        
        output += "<input format>\n"
        output += f"{self.__problem.input_format}"
        output += "</input format>\n"
        
        output += "<output format>\n"
        output += f"{self.__problem.output_format}"
        output += "</output format>\n"
        
        output += f"\n{self.get_cases_test_of_problem()}"
        
        return output