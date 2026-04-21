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

    vector<long long> a;
    a.reserve(N);
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }

    int pos = 0;
    char C;
    long long V;

    while (cin >> C) {
        if (C == 'S') break;
        cin >> V;
        if (C == 'D') {
            pos = (pos + (int)(V % N)) % N;
        } else if (C == 'E') {
            pos = (pos - (int)(V % N)) % N;
            if (pos < 0) pos += N;
        }

        for (int i = 0; i < N; i++) {
            int idx = (pos + i) % N;
            cout << a[idx] << (i + 1 == N ? ' ' : ' ');
        }
        cout << "\n";
    }

    return 0;
}