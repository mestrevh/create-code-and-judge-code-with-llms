/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

void clamp_vector(std::vector<int>& v, int n) {
    for (int i = 0; i < n; ++i) {
        if (v[i] > 10) {
            v[i] = 10;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    clamp_vector(v, n);

    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << "\n";
    }

    return 0;
}