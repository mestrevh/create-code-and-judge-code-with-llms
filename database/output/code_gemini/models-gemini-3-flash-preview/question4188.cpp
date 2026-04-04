/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

ll get_gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll get_lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    ll g = get_gcd(a, b);
    return (a / g) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b;
    if (!(cin >> a >> b)) return 0;
    
    string s;
    if (!(cin >> s)) return 0;

    if (a <= 0 || b <= 0) {
        cout << "digite numeros inteiros positivos!" << endl;
        return 0;
    }

    string low = s;
    for (char &c : low) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }

    if (low == "mdc") {
        cout << "o mdc eh: " << get_gcd(a, b) << endl;
    } else if (low == "mmc") {
        cout << "o mmc eh: " << get_lcm(a, b) << endl;
    } else {
        cout << "nao compreendi, tente outra vez" << endl;
    }

    return 0;
}