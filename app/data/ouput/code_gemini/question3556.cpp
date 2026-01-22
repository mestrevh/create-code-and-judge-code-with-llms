/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long k, b;
    while (std::cin >> k >> b) {
        long long sum = 0;
        while (k > 0) {
            sum += k % b;
            k /= b;
        }
        std::cout << sum << std::endl;
    }
    return 0;
}
