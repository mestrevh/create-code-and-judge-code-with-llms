/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void print_evens_recursive(int n) {
    if (n < 0) {
        return;
    }
    std::cout << n << "\n";
    print_evens_recursive(n - 2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    if (n % 2 != 0) {
        n--;
    }

    print_evens_recursive(n);

    return 0;
}