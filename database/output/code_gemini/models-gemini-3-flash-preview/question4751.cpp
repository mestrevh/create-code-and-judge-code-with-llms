/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x;
    while (std::cin >> x) {
        if (x < 1200) {
            std::cout << "ABC\n";
        } else {
            std::cout << "ARC\n";
        }
    }
    return 0;
}