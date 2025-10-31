/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n, k;
    std::cin >> n >> k;
    if (n == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }
    long long time = 0;
    long long installed = 1;
    while (installed < k && installed < n) {
        installed *= 2;
        time++;
    }
    if (installed >= n) {
        std::cout << time << std::endl;
    } else {
        long long remaining = n - installed;
        long long linear_time = (remaining + k - 1) / k;
        time += linear_time;
        std::cout << time << std::endl;
    }
    return 0;
}
