/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>

std::string corrigirFrase(const std::string& frase) {
    std::unordered_map<char, char> mapeamento = {
        {'0', 'o'}, {'1', 'i'}, {'3', 'e'},
        {'4', 'a'}, {'5', 's'}
    };
    std::string resultado;
    for (char c : frase) {
        if (mapeamento.count(c)) {
            resultado += mapeamento[c];
        } else {
            resultado += c;
        }
    }
    return resultado;
}

int main() {
    std::string frase;
    std::getline(std::cin, frase);
    std::cout << corrigirFrase(frase) << std::endl;
    return 0;
}
