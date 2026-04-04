/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    if (std::cin >> n) {
        if (n % 2 == 0) {
            std::cout << "par" << "\n";
        } else {
            std::cout << "impar" << "\n";
        }
    }
    return 0;
}