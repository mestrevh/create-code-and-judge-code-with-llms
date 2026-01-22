/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double p1, p2, p3;
    std::cin >> p1 >> p2 >> p3;
    if (p1 <= p2 && p1 <= p3) {
        std::cout << "Primeiro produto\n";
    } else if (p2 <= p1 && p2 <= p3) {
        std::cout << "Segundo produto\n";
    } else {
        std::cout << "Terceiro produto\n";
    }
    return 0;
}
