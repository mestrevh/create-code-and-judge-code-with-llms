/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> v1;
    std::vector<int> v2;
    int num;

    std::cout << "Digite o vetor 1: \n";
    while (std::cin >> num && num >= 0) {
        v1.push_back(num);
    }

    std::cout << "Digite o vetor 2: \n";
    while (std::cin >> num && num >= 0) {
        v2.push_back(num);
    }

    std::sort(v1.begin(), v1.end());
    v1.erase(std::unique(v1.begin(), v1.end()), v1.end());

    std::sort(v2.begin(), v2.end());
    v2.erase(std::unique(v2.begin(), v2.end()), v2.end());

    std::vector<int> intersection;
    std::set_intersection(v1.begin(), v1.end(),
                           v2.begin(), v2.end(),
                           std::back_inserter(intersection));

    std::cout << "\n";

    std::cout << "Vetor 1 (ordenado):";
    for (int x : v1) {
        std::cout << " " << x;
    }
    std::cout << "\n";

    std::cout << "Vetor 2 (ordenado):";
    for (int x : v2) {
        std::cout << " " << x;
    }
    std::cout << "\n";

    std::cout << "Vetor interseção (ordenado):";
    for (int x : intersection) {
        std::cout << " " << x;
    }
    std::cout << "\n";

    return 0;
}
