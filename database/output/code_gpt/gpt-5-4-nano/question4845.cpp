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
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int Q;
    cin >> Q;
    while (Q--) {
        int x;
        cin >> x;
        cout << (binary_search(a.begin(), a.end(), x) ? "SIM" : "NAO") << "\n";
    }
    return 0;
}