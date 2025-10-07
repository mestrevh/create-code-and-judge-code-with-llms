/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <utility>

void troca(int &a, int &b) {
    if (a > b) {
        std::swap(a, b);
    }
}

int main() {
    int a, b;
    std::cin >> a >> b;
    troca(a, b);
    std::cout << a << " " << b << std::endl;
    return 0;
}
