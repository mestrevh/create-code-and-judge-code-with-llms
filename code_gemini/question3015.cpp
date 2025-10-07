/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int broas, paes;
    while (std::cin >> broas >> paes) {
        double total_arrecadado = (broas * 1.50) + (paes * 0.20);
        double poupanca = total_arrecadado * 0.10;
        std::cout << "O valor a ser guardado na poupança será R$ " 
                  << std::fixed << std::setprecision(2) << poupanca 
                  << std::endl;
    }
    return 0;
}
