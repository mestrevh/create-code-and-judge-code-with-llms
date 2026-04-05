/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

vector<long long> ordenar(const vector<long long>& a) {
    vector<long long> v = a;
    for (int i = 0; i < 7; i++) {
        int mn = i;
        for (int j = i + 1; j < 7; j++) {
            if (v[j] < v[mn]) mn = j;
        }
        long long tmp = v[i];
        v[i] = v[mn];
        v[mn] = tmp;
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a(7);
    for (int i = 0; i < 7; i++) {
        if (!(cin >> a[i])) return 0;
    }

    vector<long long> r = ordenar(a);

    cout << "[";
    for (int i = 0; i < 7; i++) {
        if (i) cout << ", ";
        cout << r[i];
    }
    cout << "]";
    return 0;
}