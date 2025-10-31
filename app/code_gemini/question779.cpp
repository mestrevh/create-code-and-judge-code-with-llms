/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> t(n);
    std::vector<long long> f(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> f[i];
    }

    long long currentTime = 0;

    for (int i = 0; i < n; ++i) {
        long long remainder = currentTime % f[i];
        if (remainder != 0) {
            currentTime += (f[i] - remainder);
        }
        currentTime += t[i];
    }

    std::cout << currentTime << std::endl;

    return 0;
}
