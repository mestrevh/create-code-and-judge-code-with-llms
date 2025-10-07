/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int N;
    double A;
    std::cin >> N >> A;

    double result;
    switch (N) {
        case 1:
            result = pow(A, 2);
            break;
        case 2:
            result = sqrt(A);
            break;
        case 3:
            result = fabs(A);
            break;
        case 4:
            result = log2(A);
            break;
    }

    std::cout << std::fixed << std::setprecision(2) << result << std::endl;
    return 0;
}
