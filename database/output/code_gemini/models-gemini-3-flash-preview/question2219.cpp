/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        if (n == 1) {
            std::cout << "Life Mushroom" << "\n";
        } else if (n == 2) {
            std::cout << "Fire Flower" << "\n";
        } else if (n == 3) {
            std::cout << "Boost Star" << "\n";
        } else if (n == 4) {
            std::cout << "Mega Mushroom" << "\n";
        }
    }

    return 0;
}