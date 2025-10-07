/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

int calculaSomaASCII(const std::string& palavra) {
    int soma = 0;
    for (char c : palavra) {
        soma += static_cast<int>(c);
    }
    return soma;
}

bool isPrimo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    std::string entrada;
    std::getline(std::cin, entrada);
    
    int somaPalavra = calculaSomaASCII(entrada);
    if (somaPalavra % 17 == 0) {
        std::cout << "Agora estou Putin, Bonxai!" << std::endl;
        return 0;
    }
    
    std::set<int> primos;
    for (int i = 2; i <= somaPalavra; ++i) {
        if (isPrimo(i)) {
            if (somaPalavra % i == 0) {
                primos.insert(i);
            }
        }
    }
    
    if (primos.size() >= 3) {
        somaPalavra *= 3;
    }
    
    int tentativa, somaTentativas = 0;
    for (int i = 0; i < 6; ++i) {
        std::cin >> tentativa;
        somaTentativas += tentativa;
        
        if (somaTentativas == somaPalavra) {
            std::cout << "Parabueins! Voce ajudou Bonxai a escapar." << std::endl;
            return 0;
        }
        
        if (somaTentativas > somaPalavra) {
            std::cout << "Agora voce passou dos limites!" << std::endl;
            return 0;
        }
    }
    
    std::cout << "Bonxai foi de base." << std::endl;
    return 0;
}
