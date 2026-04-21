/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void countdown(int n) {
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            std::cout << i << (j == i - 1 ? "" : "-");
        }
        std::cout << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        countdown(n);
    }

    return 0;
}