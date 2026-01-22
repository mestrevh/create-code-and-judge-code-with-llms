/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long square(long long a) {
    return a * a;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long a;
    std::cin >> a;
    std::cout << square(a) << std::endl;
    return 0;
}
