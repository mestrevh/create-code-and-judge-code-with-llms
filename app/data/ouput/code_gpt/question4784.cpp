/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> palavras(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> palavras[i];
    }
    std::string bits;
    std::cin >> bits;

    if (bits.empty()) {
        std::cout << "Sem bits no momento..." << std::endl;
        return 0;
    }

    int codigoEntrada = 0;
    std::vector<int> numeros;
    for (size_t i = 0; i < bits.size(); i += 4) {
        if (i + 3 < bits.size()) {
            std::string parte = bits.substr(i, 4);
            int numero = std::stoi(parte, nullptr, 2);
            if (numero >= 0 && numero <= 9) {
                numeros.push_back(numero);
                codigoEntrada += numero;
            } else {
                std::cout << "Numero invalido!" << std::endl;
                codigoEntrada += numero;
            }
        }
    }

    std::string senha;
    for (int numero : numeros) {
        senha += std::to_string(numero);
    }

    std::sort(palavras.begin(), palavras.end());

    std::cout << "O codigo de entrada eh: " << codigoEntrada << std::endl;
    for (const auto& palavra : palavras) {
        std::cout << palavra << senha << std::endl;
    }
    
    return 0;
}
