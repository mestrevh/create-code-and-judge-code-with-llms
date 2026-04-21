/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<long long> a;
    a.reserve(max(0, N));
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }

    long long pos;
    long long val;
    cin >> pos >> val;

    auto printVec = [&](const vector<long long>& v) {
        cout << "[ ";
        for (size_t i = 0; i < v.size(); i++) {
            if (i) cout << ' ';
            cout << v[i];
        }
        cout << " ]";
    };

    printVec(a);
    cout << "\n";

    if (pos < 0 || pos > (long long)a.size()) {
        cout << "A posicao " << pos << " estah fora do intervalo";
        return 0;
    }

    vector<long long> b;
    b.reserve(a.size() + 1);
    long long idx = pos;
    for (long long i = 0; i < (long long)a.size(); i++) {
        if (i == idx) b.push_back(val);
        b.push_back(a[(size_t)i]);
    }
    if (idx == (long long)a.size()) b.push_back(val);

    printVec(b);
    return 0;
}