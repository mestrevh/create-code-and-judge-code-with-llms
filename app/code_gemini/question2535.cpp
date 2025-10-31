/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cout << "Digite um numero:" << std::endl;
    std::cin >> n;
    if (n > 0) {
        std::cout << "O numero e positivo" << std::endl;
    } else if (n < 0) {
        std::cout << "O numero e negativo" << std::endl;
    } else {
        std::cout << "O numero e nulo" << std::endl;
    }
    return 0;
}
