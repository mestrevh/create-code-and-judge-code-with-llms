/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long memo[71];
bool vis[71];

long long f(long long x) {
    if (x < 0) return 0;
    if (x <= 2) return memo[x];
    if (vis[x]) return memo[x];
    vis[x] = true;
    memo[x] = f(x - 2) - f(x - 3);
    return memo[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memo[0] = 10;
    memo[1] = 11;
    memo[2] = 27;
    vis[0] = vis[1] = vis[2] = true;

    vector<long long> inputs;
    long long x;
    while (cin >> x) {
        inputs.push_back(x);
    }

    for (size_t i = 0; i < inputs.size(); i++) {
        cout << f(inputs[i]);
        if (i + 1 < inputs.size()) cout << "\n";
    }
    return 0;
}