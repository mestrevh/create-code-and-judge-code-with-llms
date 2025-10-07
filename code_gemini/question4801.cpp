/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    double A;
    double result;

    std::cin >> N >> A;

    switch (N) {
        case 1:
            result = pow(A, 2.0);
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
