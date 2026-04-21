/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    if (std::cin >> n) {
        if (n < 3) {
            std::cout << 0 << "\n";
        } else {
            long long diagonals = (n * (n - 3)) / 2;
            std::cout << diagonals << "\n";
        }
    }

    return 0;
}