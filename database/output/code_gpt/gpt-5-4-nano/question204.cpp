/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long A, B, C;
    if (!(cin >> A >> B >> C)) return 0;
    
    vector<long long> v = {A, B, C};
    sort(v.begin(), v.end());
    long long a = v[0], b = v[1], c = v[2];
    
    if (a + b <= c) {
        cout << 'n' << "\n";
        return 0;
    }
    
    long long a2 = a * a, b2 = b * b, c2 = c * c;
    if (a2 + b2 == c2) cout << 'r' << "\n";
    else if (a2 + b2 > c2) cout << 'a' << "\n";
    else cout << 'o' << "\n";
    
    return 0;
}