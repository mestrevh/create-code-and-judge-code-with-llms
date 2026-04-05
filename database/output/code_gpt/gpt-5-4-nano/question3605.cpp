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

    int n = (int)a.size();
    int p = 0, r = n - 1;

    int m = p + (r - p) / 2;

    long long A = a[p], B = a[m], C = a[r];
    int q;
    long long pivot;

    if ((A <= B && B <= C) || (C <= B && B <= A)) {
        pivot = B;
        q = m;
    } else if ((B <= A && A <= C) || (C <= A && A <= B)) {
        pivot = A;
        q = p;
    } else {
        pivot = C;
        q = r;
    }

    swap(a[q], a[r]);
    pivot = a[r];

    int i = p;
    for (int j = p; j < r; j++) {
        if (a[j] <= pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    q = i;

    cout << pivot << "\n";
    for (int i2 = 0; i2 < n; i2++) {
        if (i2) cout << ' ';
        cout << a[i2];
    }
    cout << "\n";
    return 0;
}