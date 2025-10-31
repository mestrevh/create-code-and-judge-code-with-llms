/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        int A;
        std::cin >> A;
        if (360 % (180 - A) == 0) {
            std::cout << "SIM\n";
        } else {
            std::cout << "NAO\n";
        }
    }
    return 0;
}
