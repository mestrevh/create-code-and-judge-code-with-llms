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
    if (a.empty()) return 0;

    for (size_t i = 0; i < a.size(); i++) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << "\n";

    int n = (int)a.size();
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && a[j - 1] > a[j]) {
            swap(a[j - 1], a[j]);
            for (int k = 0; k < n; k++) {
                if (k) cout << ' ';
                cout << a[k];
            }
            cout << "\n";
            j--;
        }
    }

    return 0;
}