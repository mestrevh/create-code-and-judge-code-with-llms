/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> voos;
    int numeroVoo, lugares;

    for (int i = 0; i < 37; i++) {
        std::cin >> numeroVoo >> lugares;
        if (numeroVoo > 0) {
            voos[numeroVoo] = lugares;
        }
    }

    int documento, vooDesejado;
    while (true) {
        std::cin >> documento;
        if (documento == 9999) break;
        std::cin >> vooDesejado;

        if (voos.find(vooDesejado) != voos.end() && voos[vooDesejado] > 0) {
            std::cout << documento << std::endl;
            voos[vooDesejado]--;
        } else {
            std::cout << "INDISPONIVEL" << std::endl;
        }
    }

    return 0;
}
