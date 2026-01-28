import requests
import time
from typing import Any, Optional

class RequestWeb:
    def get(self,
            link: str,
            params: Optional[dict] = None,
            headers: Optional[dict] = None,
            cookies: Optional[dict] = None
            ) -> Any:
        
        try:  
            response = requests.get(link,
                                    params=params,
                                    headers=headers,
                                    cookies=cookies,
                                    timeout=10)
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

        except Exception as e:
            print(f"[RequestWeb - get]: Erro desconhecido: {e}")
            return None
    
    def post(self,
             link: str,
             headers: dict,
             cookies: Optional[dict] = None,
             files: Optional[dict] = None,
             json: Optional[dict] = None) -> Any:
        try:
            response = requests.post(link,
                                    headers=headers,
                                    cookies=cookies,
                                    files=files,
                                    json=json)
            response.raise_for_status()

            print(f"[RequestWeb - post]: {link}")
            print("Submissão enviada com sucesso! Status:", response.status_code)
            time.sleep(60)
            return response

        except requests.exceptions.HTTPError as err:
            if err.response is not None:
                print(f"[RequestWeb - post]: Status: {err.response.status_code}")
                print(f"[RequestWeb - post]: Resposta: {err.response.text}")
            return None
            
        except requests.exceptions.RequestException as e:
            print(f"[RequestWeb - post]: Ocorreu um erro de conexão: {e}")
            return None
                
    def __str__():
        return "Sou apenas um facilitador para requisitar na Web"
    
request_web = RequestWeb()