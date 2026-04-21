/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long x;
    if (std::cin >> x) {
        double y = static_cast<double>(4 * x - 1);
        std::cout << "Y= " << std::fixed << std::setprecision(1) << y << std::endl;
    }
    return 0;
}