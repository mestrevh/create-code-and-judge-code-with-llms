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
    while ( (cin >> N) ) {
        if (N == 0) break;
        vector<int> P(N);
        for (int i = 0; i < N; i++) cin >> P[i];

        vector<int> pos(N + 1);
        for (int i = 0; i < N; i++) pos[P[i]] = i;

        long long inv = 0;
        vector<int> bit(N + 1, 0);
        auto add = [&](int i, int v){
            for (; i <= N; i += i & -i) bit[i] += v;
        };
        auto sum = [&](int i){
            int r = 0;
            for (; i > 0; i -= i & -i) r += bit[i];
            return r;
        };

        for (int i = 1; i <= N; i++) {
            int p = pos[i] + 1;
            inv += (long long)(i - 1) - sum(p);
            add(p, 1);
        }

        if (inv % 2 == 0) cout << "Marcelo\n";
        else cout << "Carlos\n";
    }
    return 0;
}