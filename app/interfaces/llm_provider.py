from abc import ABC, abstractmethod
from repositories.problem_repository import ProblemRepository
from utils.file_manager import file_manager
from utils.request_web import request_web
import json

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
        
        if file_manager.file_exist(path=f"{path}/question{problem.get_id()}.cpp"):
            print(f"[Generate Code]: Já foi criado o arquivo question{problem.get_id()}.cpp")
            return True
        
        code = self.send_prompt(prompt)
        
        if code[0] == "`":
            code = code[10:len(code)-3]
        
        if code is None:
            print("[File Manager]: Não é possível criar o arquivo")
            return False
        
        title = f"/*\nCódigo criado pelo {model_name}\n"
        title += "Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)\n*/\n"
        code = title + code
        
        if file_manager.create_dir(path):
            print(f"[File Manager]: {path} criado com sucesso")
        else:
            return False
        
        if not file_manager.create_file(f"question{problem.get_id()}.cpp", path, code):
            print("[File Manager]: Não foi possível criar o arquivo")
            return False
        
        return True
    
    @abstractmethod
    def evaluate_code(self, problem: ProblemRepository, path:str, prompt: any, model_name: str) -> bool:
        
        if file_manager.file_exist(path=f"{path}/judge{problem.get_id()}.md"):
            print(f"[Evaluate Code]: Já foi criado o arquivo judge{problem.get_id()}.md")
            return True
        
        response = self.send_prompt(prompt=prompt)
        
        if response is None:
            print("[File Manager]: Não é possível criar o arquivo")
            return False
        
        if file_manager.create_dir(path):
            print(f"[File Manager]: {path} criado com sucesso")
        else:
            return False
        
        response = f"# Modelo do judge: {model_name}\n\n" + response
        
        if not file_manager.create_file(f"judge{problem.get_id()}.md", path, response):
            print("[File Manager]: Não foi possível criar o arquivo")
            return False
        
        return True
    
    @abstractmethod
    def simulation_the_huxley(self, problem: ProblemRepository, code_path: str, path: str, prompt:any, model_name: str, code: str) -> bool:
        
        name_file = model_name.replace('/', '_')
        name_file = name_file.replace('.', '_')
        name_file = name_file.replace('-', '_')
        name_file = f"simulation_the_huxley_{name_file}.json"
        
        if file_manager.file_exist(path + f"/{name_file}"):
            json_file = file_manager.read_file(path + f"/{name_file}")
            json_file = json.loads(json_file)
            
            ids_existentes = [entry["problem_id_the_huxley"] for entry in json_file]
            
            if problem.get_id() in ids_existentes:
                print("[SIMULATION THE HUXLEY]: simulação já foi feita!")
                return True
            
            
        
        response_send_code_the_huxley = request_web.post_code_the_huxley(problem.get_id(),
                                                                         code=code,
                                                                         type="cpp")
        
        response_submission = {}
        response_submission["problem_id_the_huxley"] = problem.get_id()
        
        if response_send_code_the_huxley is not None:
            print(f"[Request Web]: questão {problem.get_id()} enviado ao the huxley com sucesso!")
            
            submission_the_huxley = request_web.get_last_submission_the_huxley(problem.get_id())
            
            response_submission['status_the_huxley']            = None
            response_submission['tempo_the_huxley']             = None
            response_submission['total_acertos_the_huxley']     = None
            response_submission['total_erros_the_huxley']       = None
            response_submission['total_casos_teste_the_huxley'] = None
            
            if submission_the_huxley['evaluation'] is not None:
                response_submission['status_the_huxley'] = submission_the_huxley['evaluation']
            
            if submission_the_huxley['time'] is not None:
                response_submission['tempo_the_huxley'] = submission_the_huxley['time']
            
            if submission_the_huxley['testCaseEvaluations'] is not None:
                response_submission['total_casos_teste_the_huxley'] = len(submission_the_huxley['testCaseEvaluations'])
                
                count_correct = 0
                count_not_correct = 0
                
                for case in submission_the_huxley['testCaseEvaluations']:
                    if case['evaluation'] == 'CORRECT':
                        count_correct += 1
                    else:
                        count_not_correct += 1
            
                response_submission['total_acertos_the_huxley'] = count_correct
                response_submission['total_erros_the_huxley']   = count_not_correct
            
            else:
                response_submission['total_casos_teste_the_huxley'] = 0
                response_submission['total_acertos_the_huxley']     = 0
                response_submission['total_erros_the_huxley']       = 0
                
            
        else:
            print(f"[Request Web]: questão {problem.get_id()} não foi enviado ao the huxley!")
            return False
        
        response_submission["modelo_do_coder"] = code.split("pelo ")[1].split('\n')[0]
        
        response_prompt = self.send_prompt(prompt=prompt)
        
        if response_prompt is None:
            print("[LLM SERVICE]: Não produziu resposta!")
            return False
        
        if response_prompt[0] != '{':
            response_prompt = response_prompt[8: len(response_prompt) - 3]
            print(response_prompt)
            
        try:
            content = json.loads(response_prompt)
        except json.JSONDecodeError:
            print("[File manager]: o arquivo não está formatado corretamente!")
            return False
        
        if content is None:
            print("[File Manager]: Não é possível criar o arquivo")
            return False
        
        content["modelo_judger"] = model_name
        
        instance = response_submission | content
        
        if file_manager.create_dir(path):
            print(f"[File Manager]: {path} criado com sucesso")
        else:
            return False
        
        if not file_manager.file_exist(path + f"/{name_file}"):
            if file_manager.create_file(name_file=name_file, path=path, content="[]"):
                print(f"[File Manager]: Arquivo {name_file} criado com sucesso!")
            else:
                print(f"[File Manager]: Erro ao criar o arquivo {name_file}!")
                return False
            
            json_file = []
            json_file.append(instance)
            
            with open(path + f"/{name_file}", "w", encoding="utf-8") as f:
                    json.dump(json_file, f, indent=4, ensure_ascii=False)
                    
        else:            
            try:
                json_file = file_manager.read_file(path + f"/{name_file}")
                json_file = json.loads(json_file)
                
                swap = -1
                
                for i, values in enumerate(json_file):
                    if values.get("problem_id_the_huxley") == instance['problem_id_the_huxley']:
                        swap = i
                
                if swap == -1:
                    json_file.append(instance)
                else:
                    json_file[swap] = instance
                    
                with open(path + f"/{name_file}", "w", encoding="utf-8") as f:
                    json.dump(json_file, f, indent=4, ensure_ascii=False)
            except json.JSONDecodeError:
                print("[File manager]: o arquivo não está formatado corretamente!")
                return False
                
        return True