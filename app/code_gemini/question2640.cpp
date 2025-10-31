/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double altura;
    int idade;
    std::vector<std::string> brinquedos_permitidos;

    std::cout << "Digite a altura em m:\n";
    std::cin >> altura;
    std::cout << "Digite a idade:\n";
    std::cin >> idade;

    if (altura >= 1.50 && idade >= 12) {
        brinquedos_permitidos.push_back("Barca Viking");
    }

    if (altura >= 1.40 && idade >= 14) {
        brinquedos_permitidos.push_back("Elevator of Death");
    }

    if (altura >= 1.70 || idade >= 16) {
        brinquedos_permitidos.push_back("Final Killer");
    }

    std::cout << "Voce pode andar em " << brinquedos_permitidos.size() << " brinquedos, sendo eles:\n";

    for (const std::string& brinquedo : brinquedos_permitidos) {
        std::cout << brinquedo << "\n";
    }

    return 0;
}
