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

    vector<long long> cpfs(n);
    for (int i = 0; i < n; i++) cin >> cpfs[i];

    vector<long long> notas(n);
    for (int i = 0; i < n; i++) cin >> notas[i];

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        long long cpf;
        cin >> cpf;

        auto it = lower_bound(cpfs.begin(), cpfs.end(), cpf);
        if (it != cpfs.end() && *it == cpf) {
            cout << notas[it - cpfs.begin()] << "\n";
        } else {
            cout << "NAO SE APRESENTOU\n";
        }
    }

    return 0;
}