/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long double> vals;
    long double x;
    while (cin >> x) vals.push_back(x);

    cout.setf(std::ios::fixed);
    cout << setprecision(3);
    for (size_t i = 0; i < vals.size(); i++) {
        if (i) cout << "\n";
        cout << (double)vals[i];
    }
    return 0;
}