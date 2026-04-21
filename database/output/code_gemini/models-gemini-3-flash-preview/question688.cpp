/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

typedef long long ll;

ll get_gcd(ll a, ll b) {
    while (b) {
        a %= b;
        ll tmp = a;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a, b, c;
    if (!(cin >> a >> b >> c)) return 0;
    
    ll g = get_gcd(a, b);
    
    if (g == 0) {
        if (c == 0) {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    } else {
        if (c % g == 0) {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }
    
    return 0;
}