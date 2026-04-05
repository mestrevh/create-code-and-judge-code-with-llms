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
    
    if (a < 0 || b < 0 || c < 0) {
        cout << "Erro: valores negativos nao sao permitidos\n";
        return 0;
    }
    
    array<long long, 3> v = {a, b, c};
    if (a % 2 != 0) {
        sort(v.begin(), v.end());
    } else {
        sort(v.begin(), v.end(), greater<long long>());
    }
    
    cout << v[0] << "\n" << v[1] << "\n" << v[2] << "\n";
    return 0;
}