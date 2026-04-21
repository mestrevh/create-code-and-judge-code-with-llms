/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<long long> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    vector<long long> arr = a;
    for (int i = 0; i < m; i++) {
        cout << "[";
        for (int j = 0; j < m; j++) {
            if (j) cout << ", ";
            cout << arr[j];
        }
        cout << "]";
        if (i < n) cout << "\n";
        if (i == n - 1) break;
        int idx = i;
        for (int j = i + 1; j < m; j++) {
            if (arr[j] < arr[idx]) idx = j;
        }
        swap(arr[i], arr[idx]);
    }

    int start = 0;
    vector<long long> b = a;
    for (int i = 0; i < n; i++) {
        int idx = i;
        for (int j = i + 1; j < m; j++) {
            if (b[j] < b[idx]) idx = j;
        }
        swap(b[i], b[idx]);
        cout << "[";
        for (int j = 0; j < m; j++) {
            if (j) cout << ", ";
            cout << b[j];
        }
        cout << "]";
        if (i < n - 1) cout << "\n";
    }

    return 0;
}