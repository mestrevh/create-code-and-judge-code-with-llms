import requests
import time
from typing import Any, Optional
from core.config import config

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
    
    def post_code_the_huxley(self, id: int, code: str, type: str) -> bool:
        
        link = f"https://www.thehuxley.com/api/v1/user/problems/{id}/submissions"

        headers = {
            "Accept": "application/json, text/plain, */*",
            "Authorization": "Bearer " + config.TOKEN_THE_HUXLEY,
            "Origin": "https://www.thehuxley.com",
            "Referer": f"https://www.thehuxley.com/problem/{id}/code-editor/",
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:143.0) Gecko/20100101 Firefox/14.0",
        }

        cookies = {
            "tha": config.TOKEN_THE_HUXLEY,
        }
        
        files = {}
        if type == "py":
            files = {
                "problem": (None, id),
                "language": (None, "5"),
                "file": ("solution.py", code.encode("utf-8"), "application/octet-stream")
            }
        elif type == "cpp":
            files = {
                "problem": (None, id),
                "language": (None, "4"),
                "file": ("A.cpp", code.encode("utf-8"), "application/octet-stream")
            }
            
        return self.post(link=link, headers=headers,
                                cookies=cookies, files=files)
    
    def get_last_submission_the_huxley(self, id: int) -> dict:
        link = f"https://www.thehuxley.com/api/v1/submissions/summary?problem={id}&stats=last"
        params = {'max': 1, 'sort': 'submissionDate', 'order': 'desc'}
        headers = {
            "Accept": "application/json, text/plain, */*",
            "Authorization": "Bearer " + config.TOKEN_THE_HUXLEY,
            "Referer": f"https://www.thehuxley.com/problem/{id}/",
        }
        cookies = {"tha": config.TOKEN_THE_HUXLEY}
        
        
        data = self.get(link=link, params=params,
                               headers=headers, cookies=cookies)
        
        if data is not None:
            return data[0]
        
        return None
    
    def __str__():
        return "Sou apenas um facilitador para requisitar na Web"
    
request_web = RequestWeb()