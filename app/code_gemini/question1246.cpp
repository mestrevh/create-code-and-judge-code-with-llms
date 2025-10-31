/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    while (n--) {
        long long k;
        std::cin >> k;
        long long result = k * (k * k + 1) / 2;
        std::cout << result << "\n";
    }
    return 0;
}
