/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    int p, q;
    char c;
    std::cin >> p >> c >> q;

    int result;
    if (c == '+') {
        result = p + q;
    } else {
        result = p * q;
    }

    if (result > n) {
        std::cout << "OVERFLOW" << std::endl;
    } else {
        std::cout << "OK" << std::endl;
    }

    return 0;
}