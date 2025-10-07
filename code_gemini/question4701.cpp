/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int contar_palavras_na_frase(const std::string& frase, const std::string& palavra) {
    int count = 0;
    size_t pos = 0;

    while ((pos = frase.find(palavra, pos)) != std::string::npos) {
        bool inicio_ok = (pos == 0) || !std::isalpha(frase[pos - 1]);
        
        size_t fim_pos = pos + palavra.length();
        bool fim_ok = (fim_pos == frase.length()) || !std::isalpha(frase[fim_pos]);

        if (inicio_ok && fim_ok) {
            count++;
        }
        
        pos += palavra.length();
    }

    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string palavra_alvo;
    std::cin >> palavra_alvo;

    std::string frase;
    std::getline(std::cin >> std::ws, frase);

    std::cout << contar_palavras_na_frase(frase, palavra_alvo) << std::endl;

    return 0;
}
