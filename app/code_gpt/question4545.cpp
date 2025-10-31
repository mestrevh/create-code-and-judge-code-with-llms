/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    int n, s;
    std::cin >> n;
    std::vector<double> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    std::cin >> s;

    std::unordered_set<double> seen;
    for (double num : numbers) {
        if (seen.count(s - num)) {
            std::cout << "SIM" << std::endl;
            return 0;
        }
        seen.insert(num);
    }
    std::cout << "NAO" << std::endl;
    return 0;
}
