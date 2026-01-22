/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string adjetivo;
    std::getline(std::cin, adjetivo);
    
    if (adjetivo.size() >= 3 && adjetivo.substr(adjetivo.size() - 3) == "nte") {
        std::string base = adjetivo.substr(0, adjetivo.size() - 3);
        std::cout << "Aquilo que " << base << "a." << std::endl;
    }
    
    return 0;
}
