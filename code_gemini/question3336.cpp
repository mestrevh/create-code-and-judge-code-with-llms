/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int p;
    while (std::cin >> p && p != 0) {
        int n10 = p / 10;
        int rem = p % 10;
        int n5 = rem / 5;
        rem %= 5;
        int n1 = rem;

        std::cout << n1 + n5 + n10 << "\n";
        std::cout << n1 << " " << n5 << " " << n10 << "\n";
    }

    return 0;
}
