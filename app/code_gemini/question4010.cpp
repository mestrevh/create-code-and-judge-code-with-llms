/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    double total;

    std::cout << "Digite a quantidade de macas:" << std::endl;
    std::cin >> n;

    if (n < 12) {
        total = n * 0.30;
    } else {
        total = n * 0.25;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Valor total: R$ " << total << std::endl;

    return 0;
}
