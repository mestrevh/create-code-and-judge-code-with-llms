/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

vector<long double> readVector(int n) {
    vector<long double> v(n);
    for (int i = 0; i < n; i++) {
        long double x;
        cin >> x;
        v[i] = x;
    }
    return v;
}

vector<long double> degToRad(const vector<long double>& v) {
    const long double pi = acosl(-1.0L);
    vector<long double> r(v.size());
    for (size_t i = 0; i < v.size(); i++) r[i] = v[i] * pi / 180.0L;
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    vector<long double> v = readVector(N);
    vector<long double> r = degToRad(v);
    cout.setf(std::ios::fixed);
    cout << setprecision(5);
    for (int i = 0; i < N; i++) {
        cout << (double)r[i] << "\n";
    }
    return 0;
}