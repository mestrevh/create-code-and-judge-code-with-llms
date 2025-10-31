/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, a, b;
    std::cin >> n >> a >> b;
    bool found = false;
    for (int i = a; i <= b; ++i) {
        if (i % n == 0) {
            std::cout << i << '\n';
            found = true;
        }
    }
    if (!found) {
        std::cout << "INEXISTENTE\n";
    }
    return 0;
}
