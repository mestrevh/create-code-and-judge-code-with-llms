/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstring>

long long memo[11][165];
const int OFFSET = 60;

long long solve(int q, int d) {
    if (q == 0) {
        return (d <= 0) ? 1 : 0;
    }

    if (memo[q][d + OFFSET] != -1) {
        return memo[q][d + OFFSET];
    }

    long long count = 0;
    for (int roll = 1; roll <= 6; ++roll) {
        count += solve(q - 1, d - roll);
    }

    return memo[q][d + OFFSET] = count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int Q, D;
    std::cin >> Q >> D;

    memset(memo, -1, sizeof(memo));

    std::cout << solve(Q, D) << std::endl;

    return 0;
}
