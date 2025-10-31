/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

int main() {
    int D, M;
    std::string P_str;
    std::cin >> D >> P_str >> M;

    // Calcular P
    // Transformar a string de P em um número
    long long P = std::stoll(P_str);

    long long L = P / M;
    long long V = P % M;

    std::cout << L << " " << V << std::endl;
    return 0;
}
