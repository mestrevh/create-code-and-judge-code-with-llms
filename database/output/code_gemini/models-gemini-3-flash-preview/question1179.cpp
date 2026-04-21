/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L;
    if (std::cin >> L) {
        int P = 0;
        if (L >= 1 && L <= 20) {
            P = 20 + (L * L * L);
        } else if (L >= 21 && L <= 40) {
            P = 8000 + (L - 10) * (L - 10);
        } else if (L >= 41 && L <= 60) {
            P = 9000 + 5 * L;
        } else if (L >= 61 && L <= 80) {
            P = 9300 + 2 * L;
        } else if (L >= 81 && L <= 100) {
            P = 9500 + L;
        }

        std::cout << "Potencia de : " << P << " W" << std::endl;
    }

    return 0;
}