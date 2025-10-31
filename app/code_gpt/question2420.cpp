/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>

int main() {
    int fome;
    std::cin >> fome;
    
    std::map<std::string, int> sushis = {
        {"Hossomaki", 3},
        {"Futomaki", 5},
        {"Nigirizushi", 7},
        {"Temaki", 10}
    };
    
    for (int i = 0; i < 3; ++i) {
        std::string tipo;
        int quantidade;
        std::cin >> tipo >> quantidade;
        if (sushis.find(tipo) != sushis.end()) {
            fome -= sushis[tipo] * quantidade;
        }
    }

    if (fome <= 0) {
        std::cout << "Nossa, o Japao e um otimo lugar para comer, vou dar conta do recado!" << std::endl;
    } else if (fome <= 10) {
        std::cout << "Estou satisfeito mas nao sei se darei conta do recado" << std::endl;
    } else {
        std::cout << "Uma feijoada seria bem melhor... Estou me sentindo fraco" << std::endl;
    }

    return 0;
}
