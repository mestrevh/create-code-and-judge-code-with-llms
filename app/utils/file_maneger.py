import os

class FileManager:
    """
    Essa classe tem como objetivo criar, deletar 
    ou modificar arquivos no diretório app/data/
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
    
    def dir_is_exist(self, path):
        return os.path.isdir(path)
    
    def __str__():
        return "Sou apenas um gerenciador de arquivos"
    
file_manager = FileManager() 