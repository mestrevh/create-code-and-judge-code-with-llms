/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

ull memo[101];

ull sequence(int n) {
    if (n <= 3) {
        return 1;
    }
    if (memo[n] != 0) {
        return memo[n];
    }
    return memo[n] = sequence(n - 2) + sequence(n - 3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < 101; ++i) {
        memo[i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        cout << sequence(i) << "\n";
    }

    return 0;
}