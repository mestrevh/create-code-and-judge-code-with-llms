/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    std::cin >> n;
    long long result = (n + 1) * (n + 2) / 2;
    std::cout << result << std::endl;
    return 0;
}
