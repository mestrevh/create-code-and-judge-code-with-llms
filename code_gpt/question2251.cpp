/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int n, d;
    std::cin >> n;
    std::vector<int> numbers(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    std::cin >> d;

    for (int i = 0; i < n; ++i) {
        numbers[i] = (numbers[i] + d + 10) % 10;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << numbers[i] << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
