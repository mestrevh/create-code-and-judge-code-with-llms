/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int c;
    for (int i = 1; i <= 4; ++i) {
        if (std::cin >> c && c == 1) {
            std::cout << i << "\n";
            break;
        }
    }

    return 0;
}