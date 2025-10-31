/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c;
    int h, l;
    std::cin >> a >> b >> c;
    std::cin >> h >> l;

    if ((a <= h && b <= l) || (a <= l && b <= h) ||
        (a <= h && c <= l) || (a <= l && c <= h) ||
        (b <= h && c <= l) || (b <= l && c <= h)) {
        std::cout << "S\n";
    } else {
        std::cout << "N\n";
    }

    return 0;
}
