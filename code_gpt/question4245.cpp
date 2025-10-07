/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

struct Caixa {
    int largura;
    int profundidade;
    int altura;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Caixa> caixas(n);
    std::vector<int> volumes;

    for (int i = 0; i < n; ++i) {
        std::cin >> caixas[i].largura >> caixas[i].profundidade >> caixas[i].altura;
        if (caixas[i].altura <= 10) {
            volumes.push_back(caixas[i].largura * caixas[i].profundidade * caixas[i].altura);
        }
    }

    if (volumes.empty()) {
        std::cout << "Nenhuma caixa passa pelo tunel!" << std::endl;
    } else {
        for (int volume : volumes) {
            std::cout << volume << std::endl;
        }
    }

    return 0;
}
