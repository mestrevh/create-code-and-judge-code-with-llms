/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::vector<double> notas(6);
    for (int i = 0; i < 6; ++i) {
        std::cin >> notas[i];
    }
    
    bool ganhouBrinquedo = true;
    for (int i = 1; i < 6; ++i) {
        if (notas[i] <= notas[i - 1]) {
            ganhouBrinquedo = false;
            break;
        }
    }
    
    std::cout << (ganhouBrinquedo ? "Ganha brinquedo" : "Sem brinquedo") << std::endl;
    return 0;
}
