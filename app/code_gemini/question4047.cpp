/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);

    std::vector<int> original;
    int num;
    while (ss >> num) {
        original.push_back(num);
    }

    const size_t n = original.size();

    // a) Lista Invertida
    std::vector<int> invert_list = original;
    std::reverse(invert_list.begin(), invert_list.end());

    // b) Lista Par/Ímpar
    std::vector<int> parimp_list;
    for (size_t i = 0; i < n; i += 2) {
        parimp_list.push_back(original[i]);
    }
    for (size_t i = 1; i < n; i += 2) {
        parimp_list.push_back(original[i]);
    }

    // c) Soma das listas a) e b)
    std::vector<int> soma_list;
    for (size_t i = 0; i < n; ++i) {
        soma_list.push_back(invert_list[i] + parimp_list[i]);
    }

    // Impressão
    std::cout << "Invert: ";
    for (size_t i = 0; i < n; ++i) {
        std::cout << invert_list[i];
        if (i < n - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "ParImp: ";
    for (size_t i = 0; i < n; ++i) {
        std::cout << parimp_list[i];
        if (i < n - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "Soma: ";
    for (size_t i = 0; i < n; ++i) {
        std::cout << soma_list[i];
        if (i < n - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
