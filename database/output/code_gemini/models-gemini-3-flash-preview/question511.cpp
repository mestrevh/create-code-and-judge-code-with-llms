/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int is_man, over_40;
    if (std::cin >> is_man >> over_40) {
        if (is_man == 0 && over_40 == 1) {
            std::cout << 1 << "\n";
        } else {
            std::cout << 0 << "\n";
        }
    }

    return 0;
}