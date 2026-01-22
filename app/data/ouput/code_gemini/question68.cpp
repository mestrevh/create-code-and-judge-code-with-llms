/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        return 0;
    }

    int id_gordo, id_magro;
    double peso_gordo, peso_magro;

    int current_id;
    double current_peso;

    // Initialize with the first ox's data
    std::cin >> current_id >> current_peso;
    id_gordo = current_id;
    peso_gordo = current_peso;
    id_magro = current_id;
    peso_magro = current_peso;

    // Process the remaining n-1 oxen
    for (int i = 1; i < n; ++i) {
        std::cin >> current_id >> current_peso;
        if (current_peso > peso_gordo) {
            peso_gordo = current_peso;
            id_gordo = current_id;
        }
        if (current_peso < peso_magro) {
            peso_magro = current_peso;
            id_magro = current_id;
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Gordo: id: " << id_gordo << " peso: " << peso_gordo << "Kg\n";
    std::cout << "Magro: id: " << id_magro << " peso: " << peso_magro << "Kg\n";

    return 0;
}
