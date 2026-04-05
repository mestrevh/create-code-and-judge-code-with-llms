/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static long long gcdll(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a < 0 ? -a : a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    if (!(cin >> a >> b)) return 0;
    string s;
    cin >> s;

    if (a <= 0 || b <= 0) {
        cout << "digite numeros inteiros positivos!";
        return 0;
    }

    string t = s;
    for (char &c : t) c = (char)tolower((unsigned char)c);

    if (t.size() != 3 && t.size() != 2) {
        cout << "nao compreendi, tente outra vez";
        return 0;
    }

    if (t == "mdc") {
        long long g = gcdll(a, b);
        cout << "o mdc eh: " << g;
    } else if (t == "mmc") {
        long long g = gcdll(a, b);
        long long lcm = (a / g) * b;
        cout << "o mmc eh: " << lcm;
    } else {
        cout << "nao compreendi, tente outra vez";
    }

    return 0;
}