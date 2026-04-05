/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<long long> v(5);
    for (int i = 0; i < 5; i++) {
        if (!(cin >> v[i])) return 0;
    }
    
    sort(v.begin(), v.end(), greater<long long>());
    
    for (int i = 0; i < 5; i++) {
        cout << (i + 1) << " - " << v[i] << " km/h";
        if (i + 1 < 5) cout << "\n";
    }
    return 0;
}