/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double metros;
    std::cout << "Insira um valor em metros:" << std::endl;
    if (std::cin >> metros) {
        double centimetros = metros * 100.0;
        std::cout << "Resultado: " << std::fixed << std::setprecision(1) << centimetros << std::endl;
    }

    return 0;
}