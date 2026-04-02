/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

bool buscar(int x, const std::vector<int>& L, int n) {
    for (int i = 0; i < n; ++i) {
        if (L[i] == x) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    if (!(std::cin >> x)) return 0;

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<int> L(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> L[i];
    }

    if (buscar(x, L, n)) {
        std::cout << "sim" << "\n";
    } else {
        std::cout << "nao" << "\n";
    }

    return 0;
}