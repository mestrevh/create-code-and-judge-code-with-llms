/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long initial_grains;
    std::cin >> initial_grains;
    std::string operation;
    long long amount;
    while (std::cin >> operation >> amount) {
        if (operation == "GUARDAR") {
            initial_grains += amount;
        } else if (operation == "RETIRAR") {
            if (amount > initial_grains) {
                std::cout << "Winter is here" << std::endl;
                return 0;
            }
            initial_grains -= amount;
        }
    }
    std::cout << initial_grains << std::endl;
    return 0;
}
