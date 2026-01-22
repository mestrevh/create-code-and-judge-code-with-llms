/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void solve() {
    long long a, b;
    std::cin >> a >> b;

    long long count_j = 0;
    long long j_candidate = 9;

    while (j_candidate <= b) {
        count_j++;
        if (j_candidate > 1000000000LL) {
            break;
        }
        j_candidate = j_candidate * 10 + 9;
    }

    long long result = a * count_j;
    std::cout << result << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
