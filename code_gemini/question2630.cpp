/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a1, a2, a3;
    std::cout << "Digite o valor do primeiro ângulo:\n";
    std::cin >> a1;
    std::cout << "Digite o valor do segundo ângulo:\n";
    std::cin >> a2;
    std::cout << "Digite o valor do terceiro ângulo:\n";
    std::cin >> a3;
    if (a1 > 90 || a2 > 90 || a3 > 90) {
        std::cout << "Este e um triangulo obtusangulo.\n";
    } else if (a1 == 90 || a2 == 90 || a3 == 90) {
        std::cout << "Este e um triangulo retangulo.\n";
    } else {
        std::cout << "Este e um triangulo acutangulo.\n";
    }
    return 0;
}
