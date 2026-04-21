/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    if (!(std::cin >> n)) return 0;
    long long res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    std::cout << res << "\n";
    return 0;
}