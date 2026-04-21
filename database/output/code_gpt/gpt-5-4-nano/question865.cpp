/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    if (!(cin >> M)) return 0;

    vector<long long> a(M), b(M);
    for (int i = 0; i < M; i++) cin >> a[i];
    for (int i = 0; i < M; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<long long> inter;
    int i = 0, j = 0;
    while (i < M && j < M) {
        if (a[i] == b[j]) {
            inter.push_back(a[i]);
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }

    for (size_t k = 0; k < inter.size(); k++) {
        if (k) cout << "\n";
        cout << inter[k];
    }
    if (inter.empty()) cout << "\n";
    return 0;
}