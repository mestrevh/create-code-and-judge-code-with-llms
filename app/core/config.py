from pydantic_settings import BaseSettings, SettingsConfigDict
from pydantic import Field

class Config(BaseSettings):
    
    """
        Atributos:
            apiKeyGemini - Chave da API do Gemini
            apiKeyGPT - Chave para API do GPT
            tokenTheHuxley - Token Barear para requisições na WEB, utilizando biblioteca requests
    """
    
    GEMINI_API_KEY: str
    GPT_API_KEY: str
    TOKEN_THE_HUXLEY: str
    
    model_config = SettingsConfigDict(
        env_file=".env",
        env_file_encoding="utf-8"
        extra="ignore"
    )
    
    
config = Config()