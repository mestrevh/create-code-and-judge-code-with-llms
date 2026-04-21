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

    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    vector<int> O(n), D(n);
    for (int i = 0; i < n; i++) {
        O[i] = (A[i] | B[i]);
        D[i] = (A[i] & B[i]);
    }

    vector<int> freqA(n + 1, 0), freqB(n + 1, 0);
    for (int x : A) if (0 <= x && x <= n) freqA[x]++;
    for (int x : B) if (0 <= x && x <= n) freqB[x]++;

    cout << "VetOUr:\n";
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << O[i];
    }
    cout << "\n";

    cout << "ANDrray:\n";
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << D[i];
    }
    cout << "\n";

    cout << "Frequencia em A:\n";
    for (int v = 0; v <= n; v++) {
        if (v) cout << ' ';
        cout << freqA[v];
    }
    cout << "\n";

    cout << "Frequencia em B:\n";
    for (int v = 0; v <= n; v++) {
        if (v) cout << ' ';
        cout << freqB[v];
    }
    cout << "\n";

    return 0;
}