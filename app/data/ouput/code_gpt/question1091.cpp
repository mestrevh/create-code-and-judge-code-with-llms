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
        std::cout << "0.00\n";
        return 0;
    }

    double sum = 0;
    std::ostringstream series;
    
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            int numerator = i + 1;
            int denominator = (i / 2 + 1) * 4;
            series << numerator << "/" << denominator;
        } else {
            series << "1";
        }
        if (i < N - 1) series << " + ";
        
        if (i % 2 == 0) {
            sum += static_cast<double>(i + 1) / ((i / 2 + 1) * 4);
        } else {
            sum += 1;
        }
    }
    
    std::cout << std::fixed << std::setprecision(2) << sum << std::endl;
    std::cout << series.str() << std::endl;

    return 0;
}
