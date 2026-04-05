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

    for (int i = 1; i < n; i++) {
        long long key = a[i];
        cout << "Chave: " << key << "\n";
        for (int j = i - 1; j >= 0 && a[j] > key; j--) {
            cout << "Estado Atual: ";
            for (int k = 0; k < n; k++) {
                if (k) cout << " | ";
                cout << a[k];
            }
            cout << "\n";

            a[j + 1] = a[j];
        }
        a[0] = a[0]; 
        int pos = 0;
        while (pos < n && a[pos] <= key) pos++;
        if (pos < i) {
            for (int j = i - 1; j >= 0 && a[j] > key; j--) {}
        }

        int j = i - 1;
        while (j >= 0 && a[j] > key) j--;
        a[j + 1] = key;

        bool printedFinalState = false;

        if (j + 1 != i) {
            cout << "";
        }

        int finalInsertIndex = j + 1;

        bool needsStatePrint = (finalInsertIndex < i);
        if (needsStatePrint) {
            cout << "Estado Atual: ";
            for (int k = 0; k < n; k++) {
                if (k) cout << " | ";
                cout << a[k];
            }
            cout << "\n";
        }

        if (i != n - 1) cout << "\n";
    }

    cout << "Resultado Final: ";
    for (int i = 0; i < n; i++) {
        if (i) cout << " | ";
        cout << a[i];
    }
    return 0;
}