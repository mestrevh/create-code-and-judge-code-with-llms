/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <cstdlib>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int maior_ab = (a + b + std::abs(a - b)) / 2;
    int maior_final = (maior_ab + c + std::abs(maior_ab - c)) / 2;
    std::cout << maior_final << " eh o maior" << std::endl;
    return 0;
}
