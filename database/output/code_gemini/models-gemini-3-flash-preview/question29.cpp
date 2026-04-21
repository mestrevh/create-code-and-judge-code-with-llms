/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    if (std::cin >> n) {
        int res = 0;
        while (n != 0) {
            res = res * 10 + (n % 10);
            n /= 10;
        }
        std::cout << res << "\n";
    }
    return 0;
}