/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int cost = 7;

    if (n <= 10) {
        // The cost is the base fee
    } else if (n <= 30) {
        cost += (n - 10) * 1;
    } else if (n <= 100) {
        cost += (20 * 1) + (n - 30) * 2;
    } else {
        cost += (20 * 1) + (70 * 2) + (n - 100) * 5;
    }

    std::cout << cost << std::endl;

    return 0;
}
