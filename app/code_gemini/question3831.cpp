/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> lista;
    int num;

    while (true) {
        std::cin >> num;

        if (num == 0) {
            if (lista.size() < 3) {
                std::cout << "você deve digitar pelo menos 3 números antes do 0.\n";
            } else {
                break;
            }
        } else {
            bool found = false;
            for (int elemento : lista) {
                if (elemento == num) {
                    found = true;
                    break;
                }
            }

            if (found) {
                std::cout << "número já existe na lista, tente outro.\n";
            } else {
                lista.push_back(num);
            }
        }
    }

    std::cout << "[";
    for (size_t i = 0; i < lista.size(); ++i) {
        std::cout << lista[i];
        if (i < lista.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";

    auto it_maior = std::max_element(lista.begin(), lista.end());
    int pos_maior = std::distance(lista.begin(), it_maior);
    
    auto it_menor = std::min_element(lista.begin(), lista.end());
    int pos_menor = std::distance(lista.begin(), it_menor);

    std::cout << "o maior elemento da lista é: " << *it_maior << " e ele se encontra na posição: " << pos_maior << "\n";
    std::cout << "o menor elemento da lista é: " << *it_menor << " e ele se encontra na posição: " << pos_menor << "\n";

    return 0;
}
