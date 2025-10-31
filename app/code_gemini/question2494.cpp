/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int cavalos;
    std::cout << "Digite a quantidade de cavalos\n";
    std::cin >> cavalos;
    int ferraduras = cavalos * 4;
    std::cout << "Sao necessarias " << ferraduras << " ferraduras\n";
    return 0;
}
