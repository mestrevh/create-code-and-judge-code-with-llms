/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::vector<int> v1, v2, intersection;
    std::set<int> set1, set2;
    int num;

    std::cout << "Digite o vetor 1: \n";
    while (std::cin >> num && num >= 0) {
        set1.insert(num);
    }
    
    std::cout << "Digite o vetor 2: \n";
    while (std::cin >> num && num >= 0) {
        set2.insert(num);
    }

    v1.assign(set1.begin(), set1.end());
    v2.assign(set2.begin(), set2.end());

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(intersection));

    std::cout << "Vetor 1 (ordenado): ";
    for (int x : v1) std::cout << x << " ";
    std::cout << "\nVetor 2 (ordenado): ";
    for (int x : v2) std::cout << x << " ";
    std::cout << "\nVetor interseção (ordenado): ";
    for (int x : intersection) std::cout << x << " ";
    
    return 0;
}
