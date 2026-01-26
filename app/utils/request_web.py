import requests
from typing import Dict, Any

class RequestWeb:
    def get(self, link: str) -> Dict[str, Any]:
        
        try:  
            response = requests.get(link, timeout=10)
            response.raise_for_status()
            return response.json()
        
        except requests.exceptions.HTTPError as e:
            print(f"[RequestWeb - get]: Erro no protocolo HTTP {e}")
            return None
        
        except requests.exceptions.ConnectionError:
            print(f"[RequestWeb - get]: O servidor está fora do ar")
            print(f"[RequestWeb - get]: Verifique o link: {link}")
            return None
            
        except requests.exceptions.Timeout:
            print(f"[RequestWeb - get]: O servidor demorou mais de 10 segundos")
            return None
            
    def __str__():
        return "Sou apenas um facilitador para requisitar na Web"
    
request_web = RequestWeb()