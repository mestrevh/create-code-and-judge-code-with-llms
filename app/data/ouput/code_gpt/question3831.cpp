/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::vector<int> lista;
    std::set<int> numeros;
    int num;

    while (true) {
        std::cin >> num;
        if (num == 0) {
            if (lista.size() < 3) {
                std::cout << "você deve digitar pelo menos 3 números antes do 0." << std::endl;
            } else {
                break;
            }
        } else {
            if (numeros.find(num) != numeros.end()) {
                std::cout << "número já existe na lista, tente outro." << std::endl;
            } else {
                lista.push_back(num);
                numeros.insert(num);
            }
        }
    }

    std::cout << "[";
    for (size_t i = 0; i < lista.size(); ++i) {
        std::cout << lista[i];
        if (i < lista.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    auto max_elem = std::max_element(lista.begin(), lista.end());
    auto min_elem = std::min_element(lista.begin(), lista.end());
    
    std::cout << "o maior elemento da lista é: " << *max_elem 
              << " e ele se encontra na posição: " << std::distance(lista.begin(), max_elem) << std::endl;
    std::cout << "o menor elemento da lista é: " << *min_elem 
              << " e ele se encontra na posição: " << std::distance(lista.begin(), min_elem) << std::endl;

    return 0;
}
