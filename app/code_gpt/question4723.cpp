/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> compras = {"leite", "manteiga", "ovos"};
    std::string itemAdicionar, itemRemover;
    
    std::getline(std::cin, itemAdicionar);
    std::getline(std::cin, itemRemover);
    
    compras.push_back(itemAdicionar);
    compras.erase(std::remove(compras.begin(), compras.end(), itemRemover), compras.end());
    
    std::cout << "[";
    for (size_t i = 0; i < compras.size(); i++) {
        std::cout << "'" << compras[i] << "'";
        if (i < compras.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
    
    return 0;
}
