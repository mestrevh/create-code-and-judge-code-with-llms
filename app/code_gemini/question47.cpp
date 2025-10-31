/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n) {
        if (n < 1000 || n > 9999) {
            break;
        }
        int part1 = n / 100;
        int part2 = n % 100;
        int sum = part1 + part2;
        if (sum * sum == n) {
            std::cout << "propriedade do 3025!\n";
        } else {
            std::cout << "numero comum\n";
        }
    }
    return 0;
}
