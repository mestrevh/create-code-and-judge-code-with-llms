/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double cache;
    std::cin >> cache;

    double total_arrecadado = 0.0;
    std::string curso;
    std::string nome;

    while (std::cin >> curso >> nome) {
        if (curso == "CC") {
            total_arrecadado += 5.0;
        } else if (curso == "EC") {
            total_arrecadado += 10.0;
        } else {
            total_arrecadado += 15.0;
        }
    }

    if (total_arrecadado >= cache) {
        std::cout << "Cebruthius!" << std::endl;
    } else {
        std::cout << "Escamou!" << std::endl;
    }

    return 0;
}
