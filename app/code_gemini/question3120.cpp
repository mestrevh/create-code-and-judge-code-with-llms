/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int d;
    std::cin >> d;
    if (d <= 10) {
        std::cout << "Arthur\n";
    } else if (d <= 30) {
        std::cout << "Luiz\n";
    } else if (d <= 100) {
        std::cout << "Pedro\n";
    } else {
        std::cout << "Nenhum\n";
    }
    return 0;
}
