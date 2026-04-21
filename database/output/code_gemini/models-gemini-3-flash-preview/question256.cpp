/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<int> a(n);
    std::vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> a[i])) break;
    }
    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> b[i])) break;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << "\n" << b[i] << "\n";
    }

    return 0;
}