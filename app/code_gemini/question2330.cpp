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
    if (n % 2 == 0) {
        std::cout << "O numero eh " << n << " e ele eh par\n";
    } else {
        std::cout << "O numero eh " << n << " e ele eh impar\n";
    }
    return 0;
}
