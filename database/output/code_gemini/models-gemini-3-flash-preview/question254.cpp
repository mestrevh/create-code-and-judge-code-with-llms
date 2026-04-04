/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        for (int i = 0; i < n; ++i) {
            long long val;
            if (std::cin >> val) {
                std::cout << (val * 2) << "\n";
            }
        }
    }

    return 0;
}