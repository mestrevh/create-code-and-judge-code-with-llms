/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int countSubtractions(int x, int y) {
    if (y == 0) {
        return 0;
    }
    return x / y;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, y;
    std::cin >> x;
    std::cin >> y;
    std::cout << countSubtractions(x, y) << std::endl;
    return 0;
}
