/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, N;
    if (!(cin >> V >> N)) return 0;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    bool ok = false;
    for (int i = 0; i < N && !ok; i++) {
        for (int j = i + 1; j < N && !ok; j++) {
            for (int k = j + 1; k < N && !ok; k++) {
                if (a[i] + a[j] + a[k] == V) ok = true;
            }
        }
    }

    if (ok) cout << "Zeca nao vai ter que trabalhar!";
    else cout << "Zeca vai ter que trabalhar.";
    return 0;
}