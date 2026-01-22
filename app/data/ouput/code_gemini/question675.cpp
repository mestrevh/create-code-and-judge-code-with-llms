/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long x1, y1, x2, y2, x3, y3;
    int S;
    std::cin >> x1 >> y1 >> x2 >> y2 >> S >> x3 >> y3;
    long long val = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if ((S == 0 && val > 0) || (S == 1 && val < 0)) {
        std::cout << "S\n";
    } else {
        std::cout << "N\n";
    }
    return 0;
}
