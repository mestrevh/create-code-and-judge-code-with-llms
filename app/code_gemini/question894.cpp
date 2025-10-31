/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int N, D;
int ans = 0;

void solve(int k, int heads) {
    if (k == N) {
        int tails = N - heads;
        if (std::abs(heads - tails) == D) {
            ans++;
        }
        return;
    }

    solve(k + 1, heads + 1);
    solve(k + 1, heads);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> D;

    solve(0, 0);

    std::cout << ans << std::endl;

    return 0;
}
