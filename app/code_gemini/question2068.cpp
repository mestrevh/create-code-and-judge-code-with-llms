/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k;
    std::cin >> n >> k;
    long long sum = 0;
    while (n > 0) {
        sum += n;
        n -= k;
    }
    std::cout << sum << std::endl;
    return 0;
}
