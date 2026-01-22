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
    long long total_insensibility = 0;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        long long dx = x2 - x1;
        long long dy = y2 - y1;
        total_insensibility += (dx * dx) + (dy * dy);
    }
    std::cout << total_insensibility << std::endl;
    return 0;
}
