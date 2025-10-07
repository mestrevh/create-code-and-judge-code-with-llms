/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int result = (c > a) ? (2 * a) : (3 * b);
    std::cout << result << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
