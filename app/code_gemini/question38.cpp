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
    double R;
    std::cin >> N >> R;
    const double PI = acos(-1.0);
    double perimeter = 2.0 * N * R * sin(PI / N);
    std::cout << std::fixed << std::setprecision(2) << perimeter << std::endl;
    return 0;
}
