/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, n;
    std::cin >> x >> n;
    int count = (n - 1) / x;
    std::cout << "O numero " << x << " tem " << count << " multiplos menores que " << n << "." << std::endl;
    return 0;
}
