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
        int d1 = n / 100;
        int d2 = (n / 10) % 10;
        int d3 = n % 10;
        int reversed = d3 * 100 + d2 * 10 + d1;
        std::cout << reversed << std::endl;
    }
    return 0;
}