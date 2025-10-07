/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int subtrair(int a, int b) {
    return a - b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    std::cin >> a;
    std::cin >> b;
    int resultado = subtrair(a, b);
    std::cout << resultado << std::endl;
    return 0;
}
