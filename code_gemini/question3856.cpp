/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int alto_count = 0;
    int medio_count = 0;
    int baixo_count = 0;

    int max_altura = INT_MIN;
    int min_altura = INT_MAX;

    std::set<int> alturas_distintas;

    for (int i = 0; i < n; ++i) {
        int h;
        std::cin >> h;

        if (h >= 100) {
            alto_count++;
        } else if (h >= 50) {
            medio_count++;
        } else {
            baixo_count++;
        }

        if (h > max_altura) {
            max_altura = h;
        }
        if (h < min_altura) {
            min_altura = h;
        }

        alturas_distintas.insert(h);
    }

    std::cout << alturas_distintas.size() << "\n";
    std::cout << alto_count << "\n";
    std::cout << medio_count << "\n";
    std::cout << baixo_count << "\n";
    std::cout << max_altura - min_altura << "\n";

    return 0;
}
