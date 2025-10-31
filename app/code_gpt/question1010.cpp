/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int N;
    std::cin >> N;

    double pi = 0.0;
    for (int i = 0; i < N; ++i) {
        pi += (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);
    }
    pi *= 4;

    std::cout << std::fixed << std::setprecision(5) << pi << std::endl;
    return 0;
}
