/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long A, B;
    if (!(std::cin >> A >> B)) return 0;

    long long diff = A - B;
    if (diff < 0) diff = -diff;

    if (diff == 0) {
        std::cout << 0 << "\n";
    } else if (diff == 1) {
        std::cout << 2 << "\n";
    } else {
        // For diff >= 2, the minimum number of moves is ceil(diff / 3)
        // Using integer arithmetic: (diff + 2) / 3
        std::cout << (diff + 2) / 3 << "\n";
    }

    return 0;
}