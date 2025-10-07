/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cstring>

long long memo[101];

long long solve(int k) {
    if (k <= 3) {
        return 1;
    }
    if (memo[k] != -1) {
        return memo[k];
    }
    return memo[k] = solve(k - 2) + solve(k - 3);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    memset(memo, -1, sizeof(memo));

    for (int i = 1; i <= n; ++i) {
        std::cout << solve(i) << "\n";
    }

    return 0;
}
