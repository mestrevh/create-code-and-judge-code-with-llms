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
    vector<long long> V(N);
    for (int i = 0; i < N; i++) cin >> V[i];

    auto printSegment = [&](int l, int r) {
        cout << "{";
        for (int i = l; i <= r; i++) {
            if (i > l) cout << ", ";
            cout << V[i];
        }
        cout << "}";
    };

    function<void(int,int)> mergesort = [&](int l, int r) {
        if (l >= r) return;
        int m = (l + r) / 2;

        cout << "Separando o array V[" << l << "..."
             << r << "] : ";
        printSegment(l, r);
        cout << " em V[" << l << "..." << m << "] : ";
        printSegment(l, m);
        cout << " e V[" << (m + 1) << "..." << r << "] : ";
        printSegment(m + 1, r);
        cout << "\n";

        mergesort(l, m);
        mergesort(m + 1, r);

        cout << "Executando o merge nos arrays {";
        for (int i = l; i <= m; i++) {
            if (i > l) cout << ", ";
            cout << V[i];
        }
        cout << "} e {";
        for (int i = m + 1; i <= r; i++) {
            if (i > m + 1) cout << ", ";
            cout << V[i];
        }
        cout << "}\n";

        vector<long long> tmp;
        tmp.reserve(r - l + 1);
        int i = l, j = m + 1;
        while (i <= m && j <= r) {
            if (V[i] <= V[j]) tmp.push_back(V[i++]);
            else tmp.push_back(V[j++]);
        }
        while (i <= m) tmp.push_back(V[i++]);
        while (j <= r) tmp.push_back(V[j++]);

        for (int k = 0; k < (int)tmp.size(); k++) V[l + k] = tmp[k];

        cout << "array ordenado : ";
        printSegment(l, r);
        cout << "\n";
    };

    mergesort(0, N - 1);

    cout << "\nO array ordenado : ";
    for (int i = 0; i < N; i++) {
        if (i) cout << ' ';
        cout << V[i];
    }
    return 0;
}