/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << "DIGITE O VALOR A:" << std::endl;
    std::cout << "DIGITE O VALOR B:" << std::endl;
    std::cout << "DIGITE O VALOR C:" << std::endl;
    std::cout << "DIGITE O VALOR D:" << std::endl;
    std::cout << "DIFERENCA = " << (a * b - c * d) << std::endl;
    return 0;
}
