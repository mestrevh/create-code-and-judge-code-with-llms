/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<long long> a(5);
    for (int i = 0; i < 5; i++) {
        if (!(cin >> a[i])) return 0;
    }
    
    sort(a.begin(), a.end());
    cout << a[0] << "\n" << a[2] << "\n" << a[4] << "\n";
    return 0;
}