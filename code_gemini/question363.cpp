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

    long long p, q;
    char c;
    std::cin >> p >> c >> q;

    long long result;
    if (c == '+') {
        result = p + q;
    } else {
        result = p * q;
    }

    if (result > n) {
        std::cout << "OVERFLOW\n";
    } else {
        std::cout << "OK\n";
    }

    return 0;
}
