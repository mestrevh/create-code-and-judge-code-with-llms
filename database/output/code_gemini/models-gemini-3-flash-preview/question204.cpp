/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long s[3];
    if (!(std::cin >> s[0] >> s[1] >> s[2])) return 0;

    std::sort(s, s + 3);

    if (s[0] + s[1] <= s[2]) {
        std::cout << 'n' << std::endl;
    } else {
        long long a2_plus_b2 = s[0] * s[0] + s[1] * s[1];
        long long c2 = s[2] * s[2];

        if (a2_plus_b2 == c2) {
            std::cout << 'r' << std::endl;
        } else if (a2_plus_b2 > c2) {
            std::cout << 'a' << std::endl;
        } else {
            std::cout << 'o' << std::endl;
        }
    }

    return 0;
}