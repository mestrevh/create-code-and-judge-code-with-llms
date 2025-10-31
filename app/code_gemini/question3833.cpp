/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, c;
    std::cin >> a >> c;
    for (int i = 0; i < c; ++i) {
        if (30 % (a + 1) == 0) {
            std::cout << "Curvou\n";
        } else {
            std::cout << "Pedro se cagou todo e foi pego.\n";
            return 0;
        }
        a++;
    }
    return 0;
}
