/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> compras = {"leite", "manteiga", "ovos"};

    std::string item_para_adicionar;
    std::cin >> item_para_adicionar;

    std::string item_para_remover;
    std::cin >> item_para_remover;

    compras.push_back(item_para_adicionar);

    compras.erase(std::remove(compras.begin(), compras.end(), item_para_remover), compras.end());

    std::cout << "['";
    for (size_t i = 0; i < compras.size(); ++i) {
        std::cout << compras[i];
        if (i < compras.size() - 1) {
            std::cout << "', '";
        }
    }
    std::cout << "']" << std::endl;

    return 0;
}
