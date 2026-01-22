/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve() {
    int N, H;
    std::cin >> N >> H;

    std::string s(N - H, '0');
    s += std::string(H, '1');

    do {
        std::cout << s << '\n';
    } while (std::next_permutation(s.begin(), s.end()));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int test_cases;
    std::cin >> test_cases;

    for (int i = 0; i < test_cases; ++i) {
        if (i > 0) {
            std::cout << '\n';
        }
        solve();
    }

    return 0;
}
