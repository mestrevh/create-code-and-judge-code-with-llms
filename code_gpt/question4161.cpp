/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    float A, B;
    int N;
    float C;

    std::cin >> A >> B >> N >> C;

    float base = (B - A) / N;
    float soma = 0.0;

    for (int i = 0; i < N; ++i) {
        float x = A + base * (i + 1);
        soma += x * x * base;
    }

    if (soma > C)
        std::cout << "Maior" << std::endl;
    else if (soma < C)
        std::cout << "Menor" << std::endl;
    else
        std::cout << "Igual" << std::endl;

    return 0;
}
