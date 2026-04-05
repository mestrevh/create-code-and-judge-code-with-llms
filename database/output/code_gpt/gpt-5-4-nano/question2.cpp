/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<long long> a(3);
    for (int i = 0; i < 3; i++) {
        if (!(cin >> a[i])) return 0;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < 3; i++) {
        cout << a[i] << "\n";
    }
    return 0;
}