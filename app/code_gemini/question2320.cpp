/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

unsigned long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int y;
    int total_laps = 0;

    while (std::cin >> y) {
        total_laps += y;
        unsigned long long shots = factorial(y);

        if (shots < 50) {
            shots *= 2;
        }

        std::cout << shots << std::endl;
    }

    if (total_laps > 100) {
        std::cout << "WildCats, get the head in the game!" << std::endl;
    }

    return 0;
}
