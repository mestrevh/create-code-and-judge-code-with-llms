/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <sstream>

int main() {
    int N;
    std::cin >> N;

    if (N == 0) {
        std::cout << "0.00" << std::endl;
        return 0;
    }

    double sum = 0.0;
    std::ostringstream series;

    for (int i = 1; i <= N; ++i) {
        if (i > 1) series << " + ";
        series << i << "/" << (i * 3);
        sum += static_cast<double>(i) / (i * 3);
    }

    std::cout << series.str() << std::endl;
    std::cout << std::fixed << std::setprecision(2) << sum << std::endl;

    return 0;
}
