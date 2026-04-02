/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        if (n == 1) {
            std::cout << "Life Mushroom" << std::endl;
        } else if (n == 2) {
            std::cout << "Fire Flower" << std::endl;
        } else if (n == 3) {
            std::cout << "Boost Star" << std::endl;
        } else if (n == 4) {
            std::cout << "Mega Mushroom" << std::endl;
        }
    }

    return 0;
}