/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m;
    if (std::cin >> m) {
        if (m >= 1 && m <= 12) {
            int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            std::cout << "Numero de dias do mes " << m << "  : " << days[m] << " dias" << std::endl;
        } else {
            std::cout << "Voce entrou com um mes invalido !" << std::endl;
        }
    }

    return 0;
}