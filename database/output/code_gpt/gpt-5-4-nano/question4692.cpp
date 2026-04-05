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

    auto printArray = [&](const vector<long long>& v) {
        for (size_t i = 0; i < v.size(); i++) {
            if (i) cout << ' ';
            cout << v[i];
        }
        cout << "\n";
    };

    printArray(a);

    int n = (int)a.size();
    for (int i = 0; i < n - 1; i++) {
        int mn = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[mn]) mn = j;
        }
        if (mn != i) {
            long long val = a[mn];
            for (int k = mn; k > i; k--) a[k] = a[k - 1];
            a[i] = val;
            printArray(a);
        }
    }

    return 0;
}