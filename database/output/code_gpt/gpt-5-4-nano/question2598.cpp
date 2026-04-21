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
    a.reserve(max(0, N));
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }

    long long target;
    cin >> target;

    cout << "[ ";
    for (int i = 0; i < (int)a.size(); i++) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << " ]\n";

    if (a.empty()) {
        cout << "A lista estah vazia - nao eh possivel remover elemento";
        return 0;
    }

    int pos = -1;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == target) {
            pos = i;
            break;
        }
    }

    cout << "Nao eh possivel remover o elemento " << target << "\n";

    if (pos == -1) return 0;

    vector<long long> b;
    b.reserve(max(0, N - 1));
    for (int i = 0; i < (int)a.size(); i++) {
        if (i == pos) continue;
        b.push_back(a[i]);
    }

    for (int i = 0; i < (int)b.size(); i++) {
        cout << "";
    }

    cout << "[ ";
    for (int i = 0; i < (int)b.size(); i++) {
        if (i) cout << ' ';
        cout << b[i];
    }
    cout << " ]";
    return 0;
}