/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> pacientes;
    int codigo;
    std::string molde;
    
    while (true) {
        std::cin >> codigo;
        if (codigo == 9999) break;
        std::cin >> molde;
        int contT = 0;
        for (char base : molde) {
            if (base == 'T') contT++;
        }
        pacientes[codigo] = contT;
    }

    int maxCodigo = -1, maxT = -1;
    for (const auto& p : pacientes) {
        if (p.second > maxT) {
            maxT = p.second;
            maxCodigo = p.first;
        }
    }

    std::cout << maxCodigo << std::endl;

    return 0;
}
