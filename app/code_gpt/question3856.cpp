/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> alturas(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> alturas[i];
    }

    std::set<int> distintas(alturas.begin(), alturas.end());
    int altos = 0, medios = 0, baixos = 0;
    int max_height = *std::max_element(alturas.begin(), alturas.end());
    int min_height = *std::min_element(alturas.begin(), alturas.end());

    for (int h : alturas) {
        if (h >= 100) altos++;
        else if (h >= 50) medios++;
        else baixos++;
    }

    std::cout << distintas.size() << "\n" 
              << altos << "\n" 
              << medios << "\n" 
              << baixos << "\n" 
              << max_height - min_height << "\n";

    return 0;
}
