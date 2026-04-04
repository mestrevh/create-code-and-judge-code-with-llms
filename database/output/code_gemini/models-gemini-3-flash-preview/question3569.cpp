/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    if (std::cin >> a >> b) {
        double third_angle = 180.0 - (double)(a + b);
        std::cout << "3o angulo=" << std::fixed << std::setprecision(6) << third_angle << std::endl;
    }
    return 0;
}