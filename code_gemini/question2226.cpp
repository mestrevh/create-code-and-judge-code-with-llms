/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    switch (n) {
        case 1:
            std::cout << "Life Mushroom\n";
            break;
        case 2:
            std::cout << "Fire Flower\n";
            break;
        case 3:
            std::cout << "Boost Star\n";
            break;
        case 4:
            std::cout << "Mega Mushroom\n";
            break;
    }
    return 0;
}
