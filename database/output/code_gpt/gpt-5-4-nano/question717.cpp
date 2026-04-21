/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    if (!(cin >> M >> N)) return 0;

    vector<long long> a;
    a.reserve((size_t)M * N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            long long x;
            cin >> x;
            a.push_back(x);
        }
    }

    sort(a.begin(), a.end());

    int idx = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (j) cout << ' ';
            cout << a[idx++];
        }
        cout << "\n";
    }
    return 0;
}