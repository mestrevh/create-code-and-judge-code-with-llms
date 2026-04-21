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

    int pos;
    if (!(cin >> pos)) pos = 0;

    auto printList = [&](const vector<long long>& v) {
        cout << "[";
        for (size_t i = 0; i < v.size(); i++) {
            if (i) cout << ' ';
            cout << v[i];
        }
        cout << " ]";
    };

    printList(a);
    cout << "\n";

    if (a.empty()) {
        cout << "A lista estah vazia - nao eh possivel remover elementos";
        return 0;
    }

    bool invalid = false;
    long long removed = 0;
    if (pos == -1) {
        removed = a.back();
    } else if (pos >= 0 && pos < (int)a.size()) {
        removed = a[pos];
    } else if (pos >= 1 && pos <= (int)a.size()) {
        removed = a[pos - 1];
    } else {
        invalid = true;
    }

    if (invalid) {
        cout << "Nao eh possivel remover o elemento";
        return 0;
    }

    cout << "O item " << removed << " serah removido da lista\n";

    vector<long long> b;
    for (int i = 0; i < (int)a.size(); i++) {
        int removeIndex = -1;
        if (pos == -1) removeIndex = (int)a.size() - 1;
        else if (pos >= 0 && pos < (int)a.size()) removeIndex = pos;
        else if (pos >= 1 && pos <= (int)a.size()) removeIndex = pos - 1;

        if (i == removeIndex) continue;
        b.push_back(a[i]);
    }

    printList(b);
    return 0;
}