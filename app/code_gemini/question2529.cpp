/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    std::cin >> a >> b;
    if (a > b) {
        std::cout << "A eh maior\n";
    } else if (b > a) {
        std::cout << "B eh maior\n";
    } else {
        std::cout << "iguais\n";
    }
    return 0;
}
