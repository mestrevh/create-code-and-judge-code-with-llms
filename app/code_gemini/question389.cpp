/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<double> notas(6);
    for (int i = 0; i < 6; ++i) {
        std::cin >> notas[i];
    }

    bool melhora = true;
    for (int i = 1; i < 6; ++i) {
        if (notas[i] <= notas[i - 1]) {
            melhora = false;
            break;
        }
    }

    if (melhora) {
        std::cout << "Ganha brinquedo\n";
    } else {
        std::cout << "Sem brinquedo\n";
    }

    return 0;
}
