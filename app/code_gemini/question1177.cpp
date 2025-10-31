/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void solve() {
    int p, s, t;
    std::cin >> p >> s >> t;

    bool has_greater_than_ten = (p > 10 || s > 10 || t > 10);
    bool has_even = (p % 2 == 0 || s % 2 == 0 || t % 2 == 0);
    bool has_zero = (p == 0 || s == 0 || t == 0);

    if (has_greater_than_ten && has_even && !has_zero) {
        std::cout << "Sim\n";
    } else {
        std::cout << "Nao\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
