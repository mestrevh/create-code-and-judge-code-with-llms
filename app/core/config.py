from pydantic_settings import BaseSettings, SettingsConfigDict
from pydantic import Field

class Config(BaseSettings):
    
    """
        Atributos:
            apiKeyGemini - Chave da API do Gemini
            apiKeyGPT - Chave para API do GPT
            tokenTheHuxley - Token Barear para requisições na WEB, utilizando biblioteca requests
    """
    
    apiKeyGemini: str
    apiKeyGPT: str
    tokenTheHuxley: str
    
    model_config = SettingsConfigDict(
        env_file=".env",
        env_file_encoding="utf-8"
        extra="ignore"
    )
    
    
config = Config()