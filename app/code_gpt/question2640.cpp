/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    double altura;
    int idade;
    std::vector<std::string> brinquedos;

    std::cout << "Digite a altura em m:\n";
    std::cin >> altura;
    std::cout << "Digite a idade:\n";
    std::cin >> idade;

    if (altura >= 1.50 && idade >= 12) brinquedos.push_back("Barca Viking");
    if (altura >= 1.40 && idade >= 14) brinquedos.push_back("Elevator of Death");
    if (altura >= 1.70 || idade >= 16) brinquedos.push_back("Final Killer");

    std::cout << "Voce pode andar em " << brinquedos.size() << " brinquedos, sendo eles:\n";
    for (const auto& brinquedo : brinquedos) {
        std::cout << brinquedo << "\n";
    }
    
    return 0;
}
