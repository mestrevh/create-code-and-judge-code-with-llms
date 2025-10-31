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

    int n;
    double t;
    std::cin >> n >> t;

    std::vector<int> casas(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> casas[i];
    }

    std::vector<double> pes(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> pes[i];
    }

    int casa_encontrada = -1;
    for (int i = 0; i < n; ++i) {
        if (pes[i] == t) {
            casa_encontrada = casas[i];
            break;
        }
    }

    if (casa_encontrada != -1) {
        std::cout << "Cinderela mora na casa " << casa_encontrada << "!\n";
    } else {
        std::cout << "Nenhuma das jovens e a moca do baile.\n";
    }

    return 0;
}
