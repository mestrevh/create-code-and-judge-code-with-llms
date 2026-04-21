/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

long long memo[101];
bool computed[101];

long long solve(int x) {
    if (x == 0) return 10;
    if (x == 1) return 11;
    if (x == 2) return 27;
    if (computed[x]) return memo[x];

    memo[x] = solve(x - 2) - solve(x - 3);
    computed[x] = true;
    return memo[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    while (cin >> x) {
        cout << solve(x) << "\n";
    }

    return 0;
}