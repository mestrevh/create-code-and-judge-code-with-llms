/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> freqA(n + 1, 0);
    vector<int> freqB(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] >= 0 && a[i] <= n) {
            freqA[a[i]]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] >= 0 && b[i] <= n) {
            freqB[b[i]]++;
        }
    }

    cout << "VetOUr:" << "\n";
    for (int i = 0; i < n; ++i) {
        cout << (a[i] | b[i]) << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    cout << "ANDrray:" << "\n";
    for (int i = 0; i < n; ++i) {
        cout << (a[i] & b[i]) << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    cout << "Frequencia em A:" << "\n";
    for (int i = 0; i <= n; ++i) {
        cout << freqA[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    cout << "Frequencia em B:" << "\n";
    for (int i = 0; i <= n; ++i) {
        cout << freqB[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}