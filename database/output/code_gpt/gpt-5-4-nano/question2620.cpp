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

    vector<string> names(N);
    vector<long long> qty(N);

    for (int i = 0; i < N; i++) cin >> names[i] >> qty[i];

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        string qname;
        long long y;
        cin >> qname >> y;

        int idx = -1;
        for (int j = 0; j < N; j++) {
            if (names[j] == qname) {
                idx = j;
                break;
            }
        }

        if (idx == -1) continue;

        if (qty[idx] >= y) {
            qty[idx] -= y;
            cout << "Tem " << qty[idx] << " " << qname << " no estoque\n";
        } else {
            cout << "Nao tem " << qname << " suficiente no estoque\n";
        }
    }

    return 0;
}