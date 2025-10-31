/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long d;
    int c;
    std::cin >> d >> c;
    long long ticks_per_house = (d * 108000LL) / c;
    std::cout << ticks_per_house << '\n';
    return 0;
}
