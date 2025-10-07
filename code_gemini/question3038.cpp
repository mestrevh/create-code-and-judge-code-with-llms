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
        int R1, R2;
        std::cin >> R1 >> R2;
        std::cout << R1 + R2 << "\n";
    }
    return 0;
}
