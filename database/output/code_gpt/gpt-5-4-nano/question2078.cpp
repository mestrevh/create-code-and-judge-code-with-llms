/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> a(max(0, N));
    for (int i = 0; i < N; i++) cin >> a[i];

    long long total = 0;
    if (N == 0) {
        string cmd;
        return 0;
    }

    vector<char> collected(N, 0);

    int pos = 0;
    if (!collected[pos]) {
        total += a[pos];
        collected[pos] = 1;
    }

    string cmd;
    while (cin >> cmd) {
        if (cmd.empty()) continue;
        char sign = cmd[0];
        long long k = 0;
        for (size_t i = 1; i < cmd.size(); i++) {
            if (isdigit((unsigned char)cmd[i])) k = k * 10 + (cmd[i] - '0');
        }
        if (k == 0) continue;

        long long delta = (sign == '+') ? k : -k;
        long long np = (long long)pos + delta;
        np %= N;
        if (np < 0) np += N;
        pos = (int)np;

        if (!collected[pos]) {
            total += a[pos];
            collected[pos] = 1;
        }
    }

    cout << total << "\n";
    return 0;
}