/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void print_reversed() {
    int n;
    std::cin >> n;
    if (n == 0) {
        return;
    }
    print_reversed();
    std::cout << n << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    print_reversed();
    return 0;
}
