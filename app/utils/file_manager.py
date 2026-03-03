import os

class FileManager:
    """
    Essa classe tem como objetivo criar, deletar 
    ou modificar arquivos nos diretórios
    """
    
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
            print(f"Diretório '{name}' criado.")
            return True
        except OSError as e:
            print(f"Erro ao criar o diretório: {e}")
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
                print(f"[file_manager]: arquivo não existe no caminho {path}")
            except Exception as e:
                print(f"[file_manager]: erro inesperado {e}")
            
        return ""
    
    def __str__():
        return "Sou apenas um gerenciador de arquivos"
    
file_manager = FileManager() 