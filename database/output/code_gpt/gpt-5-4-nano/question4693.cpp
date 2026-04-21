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

    vector<long long> tmp(n);

    function<void(int,int)> mergesort = [&](int l, int r) {
        if (r - l <= 1) return;
        int m = (l + r) / 2;

        mergesort(l, m);
        mergesort(m, r);

        int i = l, j = m, k = l;
        while (i < m && j < r) {
            if (a[i] <= a[j]) tmp[k++] = a[i++];
            else tmp[k++] = a[j++];
        }
        while (i < m) tmp[k++] = a[i++];
        while (j < r) tmp[k++] = a[j++];

        for (int t = l; t < r; t++) a[t] = tmp[t];

        for (int t = l; t < r; t++) cout << a[t] << (t + 1 < r ? ' ' : ' ');
        cout << "\n";
    };

    mergesort(0, n);
    return 0;
}