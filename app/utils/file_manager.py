import os
import csv
import json
import pandas as pd

class FileManager:
    """
    Essa classe tem como objetivo criar, deletar 
    ou modificar arquivos nos diretórios
    """
    
    def json_to_csv(self, path: str, name_file: str) -> bool:
        try:
            print(path + f"/json/{name_file}.json")
            df = pd.read_json(path + f"/json/{name_file}.json")
            df.to_csv(path + f"/csv/{name_file}.csv", index=False, encoding='utf-8')
            return True
                  
        except Exception as e:
            print("[File Manager]: Erro na conversão csv para json")
            return False
        
    def csv_to_json(self, path: str, name_file: str) -> bool:
        try:
            df = pd.read_csv(path + f"/csv/{name_file}.csv", encoding='utf-8')
            df.to_json(path + f"/json/{name_file}.json", orient='records', indent=4, force_ascii=False)
            return True
                    
        except Exception as e:
            print("[File Manager]: Erro na conversão")
            return False
    
    def create_file(self, name_file: str, path: str, content: str) -> bool:
        try:
            
            path_file = os.path.join(path, name_file)
            
            with open(path_file, "w", encoding="utf-8") as f:
                f.write(content)

            return True
        
        except OSError as e:
            
            return False
        
    def create_dir(self, name: str) -> bool:
        try:
            os.makedirs(name, exist_ok=True)
            print(f"[File Manager]: Diretório '{name}' criado.")
            return True
        except OSError as e:
            print(f"[File Manager]: Erro ao criar o diretório: {e}")
            return False
    
    def dir_exist(self, path):
        return os.path.isdir(path)
    
    def file_exist(self, path):
        return os.path.exists(path)
    
    def read_file(self, path: str) -> str:
        if self.file_exist(path):
            try:
                with open(path,"r", encoding="utf-8") as file:
                    return file.read()
            except FileNotFoundError:
                print(f"[File Manager]: arquivo não existe no caminho {path}")
            except Exception as e:
                print(f"[File Manager]: erro inesperado {e}")
            
        return ""
    
    def __str__():
        return "[File Manager]: Sou apenas um gerenciador de arquivos"
    
file_manager = FileManager() 