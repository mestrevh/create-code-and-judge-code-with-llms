/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a;
    long long x;
    while (cin >> x) a.push_back(x);
    int n = (int)a.size();
    if (n == 0) return 0;

    auto printState = [&](int l) {
        cout << "Estado Atual: ";
        for (int i = 0; i < n; i++) {
            if (i) cout << " | ";
            cout << a[i];
        }
        cout << "\n";
    };

    for (int i = 0; i < n - 1; i++) {
        int mnIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[mnIdx]) mnIdx = j;
        }

        if (a[mnIdx] == a[i]) {
            cout << "Menor elemento neste passo: " << a[i] << "\n";
            printState(i);
            if (i != n - 2) cout << "\n";
            continue;
        }

        long long mnVal = a[mnIdx];
        swap(a[i], a[mnIdx]);

        cout << "Menor elemento neste passo: " << mnVal << "\n";
        printState(i);
        if (i != n - 2) cout << "\n";
    }

    cout << "Resultado Final: ";
    for (int i = 0; i < n; i++) {
        if (i) cout << " | ";
        cout << a[i];
    }
    cout << "\n";
    return 0;
}