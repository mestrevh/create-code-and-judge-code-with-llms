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

    if (n <= 1) {
        std::cout << 0 << std::endl;
        return 0;
    }
    
    if (n == 2) {
        std::cout << 1 << std::endl;
        return 0;
    }

    long long a = 0;
    long long b = 1;
    long long result;

    for (int i = 2; i < n; ++i) {
        result = a + b;
        a = b;
        b = result;
    }

    std::cout << b << std::endl;

    return 0;
}
