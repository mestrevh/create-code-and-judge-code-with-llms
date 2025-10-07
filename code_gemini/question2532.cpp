/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    std::cout << "Digite o valor de A:" << std::endl;
    std::cin >> a;
    std::cout << "Digite o valor de B:" << std::endl;
    std::cin >> b;
    std::cout << "O maior valor digitado foi: " << std::max(a, b) << std::endl;
    return 0;
}
