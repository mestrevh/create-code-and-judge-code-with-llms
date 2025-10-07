/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long a, b, c;
    std::cin >> a >> b >> c;
    long long x, y, z;
    std::cin >> x >> y >> z;
    long long total = (x / a) * (y / b) * (z / c);
    std::cout << total << std::endl;
    return 0;
}
