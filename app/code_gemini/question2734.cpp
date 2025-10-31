/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

void modify_vector(std::vector<int>& V, int n) {
    for (int i = 0; i < n; ++i) {
        if (V[i] > 10) {
            V[i] = 10;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> V(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i];
    }

    modify_vector(V, n);

    for (int i = 0; i < n; ++i) {
        std::cout << V[i] << '\n';
    }

    return 0;
}
