/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void tabuada(double n1, double n2, double n3) {
    if (((n1 + n2 + n3) / 3.0) >= 6.0) {
        std::cout << "Aprovado\n";
    } else {
        std::cout << "Reprovado\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double a, b, c;
    while (std::cin >> a >> b >> c) {
        tabuada(a, b, c);
    }
    return 0;
}