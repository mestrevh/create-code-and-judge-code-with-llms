/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        long long a, b, m;
        std::cin >> a >> b >> m;
        long long val1 = a % m;
        long long val2 = b % m;
        long long result = (val1 * val2) % m;
        std::cout << result << "\n";
    }
    return 0;
}
