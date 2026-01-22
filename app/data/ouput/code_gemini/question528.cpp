/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h1, m1, h2, m2, h3, m3;
    std::cin >> h1 >> m1 >> h2 >> m2 >> h3 >> m3;

    bool c1 = false;
    bool c2 = false;
    bool c3 = false;

    if (h1 >= 0 && h1 < 12) {
        c1 = true;
    }
    std::cout << (c1 ? 'v' : 'f') << '\n';

    int m2_expected = (m1 + 12) % 60;
    int h2_expected = (h1 + 3 + (m1 + 12) / 60) % 24;
    if (h2 == h2_expected && m2 == m2_expected) {
        c2 = true;
    }
    std::cout << (c2 ? 'v' : 'f') << '\n';

    int m3_expected = m2;
    int h3_expected = (h2 + 23) % 24;
    if (h3 == h3_expected && m3 == m3_expected) {
        c3 = true;
    }
    std::cout << (c3 ? 'v' : 'f') << '\n';

    if (c1 && c2 && c3) {
        std::cout << "sucesso\n";
    } else {
        std::cout << "falha\n";
    }

    return 0;
}
