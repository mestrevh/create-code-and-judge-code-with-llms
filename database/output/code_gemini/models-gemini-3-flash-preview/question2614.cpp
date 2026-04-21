/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b;
    if (!(std::cin >> a >> b)) return 0;

    for (long long i = a - 1; i > b; --i) {
        std::cout << i << "\n";
    }

    return 0;
}