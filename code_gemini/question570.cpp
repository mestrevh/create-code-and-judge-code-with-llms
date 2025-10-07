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
    int d1 = n / 100;
    int d2 = (n / 10) % 10;
    int d3 = n % 10;
    std::cout << d1 << " " << d2 << " " << d3 << std::endl;
    return 0;
}
