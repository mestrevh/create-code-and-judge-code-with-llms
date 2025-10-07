/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c, d, x;
    std::cin >> a >> b >> c >> d >> x;
    long long result = (long long)a * x * x * x + (long long)b * x * x + (long long)c * x + d;
    std::cout << result << std::endl;
    return 0;
}
