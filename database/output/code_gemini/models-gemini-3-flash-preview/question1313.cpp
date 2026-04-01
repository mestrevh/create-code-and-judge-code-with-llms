/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double p1, p2, p3;
    if (std::cin >> p1 >> p2 >> p3) {
        if (p1 <= p2 && p1 <= p3) {
            std::cout << "Primeiro produto" << std::endl;
        } else if (p2 < p1 && p2 <= p3) {
            std::cout << "Segundo produto" << std::endl;
        } else {
            std::cout << "Terceiro produto" << std::endl;
        }
    }

    return 0;
}