/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cout << "Digite a quantidade de macas:\n";
    if (std::cin >> n) {
        double total;
        if (n < 12) {
            total = n * 0.30;
        } else {
            total = n * 0.25;
        }
        std::cout << "Valor total: R$ " << total << std::endl;
    }

    return 0;
}