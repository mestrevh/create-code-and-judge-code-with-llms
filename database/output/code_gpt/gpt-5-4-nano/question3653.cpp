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
    vector<long long> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    bool firstOut = true;
    for (int i = 1; i + 1 < N; i++) {
        if (a[i] == a[i - 1] + 1 && a[i] == a[i + 1] - 1) {
            if (!firstOut) cout << "\n";
            cout << a[i];
            firstOut = false;
        }
    }
    return 0;
}