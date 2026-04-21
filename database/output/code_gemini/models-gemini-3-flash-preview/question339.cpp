/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b;
    if (std::cin >> a >> b) {
        std::cout << "O resultado da soma entre " << a << " e " << b << " = " << (a + b) << "\n";
    }

    return 0;
}