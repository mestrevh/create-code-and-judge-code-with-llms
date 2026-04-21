/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<double> a(30);
    for (int i = 0; i < 30; i++) {
        if (!(cin >> a[i])) return 0;
    }
    
    cout.setf(ios::fixed);
    cout << setprecision(10);
    for (int i = 1; i < 30; i += 2) {
        double v = a[i];
        if (i == 1) cout << v;
        else cout << "\n" << v;
    }
    return 0;
}