/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;
    
    vector<long long> v = {a, b, c};
    sort(v.begin(), v.end());
    a = v[0]; b = v[1]; c = v[2];
    
    if (a + b > c) cout << "sim";
    else cout << "nao";
    return 0;
}