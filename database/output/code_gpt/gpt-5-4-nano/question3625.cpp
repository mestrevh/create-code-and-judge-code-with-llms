/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> names(n);
    vector<long long> hp(n);

    for (int i = 0; i < n; i++) {
        cin >> names[i] >> hp[i];
    }

    while (true) {
        int idx;
        long long delta;
        if (!(cin >> idx)) break;
        if (idx == -1) {
            break;
        }
        if (idx < 0 || idx >= n) {
            continue;
        }
        hp[idx] += delta;
        for (int i = 0; i < n; i++) {
            cout << names[i] << " = " << hp[i];
            if (i + 1 < n) cout << '\n';
        }
        if (cin.peek() != EOF) cout << '\n';
    }

    return 0;
}