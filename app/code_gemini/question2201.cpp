/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int L, C;
    std::cin >> L;
    std::cin >> C;
    long long tipo1 = (long long)L * C + (long long)(L - 1) * (C - 1);
    long long tipo2 = (long long)2 * (L - 1) + (long long)2 * (C - 1);
    std::cout << tipo1 << "\n";
    std::cout << tipo2 << "\n";
    return 0;
}
