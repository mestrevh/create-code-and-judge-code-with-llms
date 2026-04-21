/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long solve(long long n) {
    if (n == 0) return 0;
    return (n % 10) + solve(n / 10);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    if (std::cin >> n) {
        if (n == 0) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << solve(n) << std::endl;
        }
    }
    return 0;
}