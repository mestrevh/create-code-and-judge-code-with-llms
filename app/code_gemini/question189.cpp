/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    std::cin >> n;
    long long k = 2LL * n - 1;
    long long count = 0;
    long long limit = static_cast<long long>(sqrt(k));
    for (long long a = 3; a <= limit; a += 2) {
        if (k % a == 0) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
