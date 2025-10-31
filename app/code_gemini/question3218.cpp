/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b;
    std::cin >> a >> b;

    long long diff = a - b;

    bool first_output = true;
    for (int i = 60; i >= 0; --i) {
        long long power_of_2 = 1LL << i;
        if (power_of_2 <= diff) {
            if (!first_output) {
                std::cout << " ";
            }
            std::cout << power_of_2;
            diff -= power_of_2;
            first_output = false;
        }
    }
    std::cout << std::endl;

    return 0;
}
