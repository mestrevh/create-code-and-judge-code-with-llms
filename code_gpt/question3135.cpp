/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    int lado = std::ceil(std::sqrt(N));
    int area = lado * lado;

    std::cout << area << std::endl;

    return 0;
}
