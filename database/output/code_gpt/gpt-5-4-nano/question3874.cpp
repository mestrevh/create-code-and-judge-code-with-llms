/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Hero {
    long long age = 0;
    long long id = 0;
    string name;
};

static bool isPrime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (long long d = 3; d * d <= n; d += 2)
        if (n % d == 0) return false;
    return true;
}

static bool isPerfectSquare(long long x) {
    if (x < 0) return false;
    long long r = llround(floor(sqrt((long double)x)));
    while (r * r < x) ++r;
    while (r * r > x) --r;
    return r * r == x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Hero h1, h2;
    if (!(cin >> h1.age >> h1.id)) return 0;
    cin >> ws;
    getline(cin, h1.name);
    if (h1.name.size() && h1.name.front() == '"') {
        if (h1.name.back() != '"') {
            string rest;
            while (getline(cin, rest)) {
                h1.name += "\n" + rest;
                if (!rest.empty() && rest.back() == '"') break;
            }
        }
        if (h1.name.size() >= 2 && h1.name.front() == '"' && h1.name.back() == '"')
            h1.name = h1.name.substr(1, h1.name.size() - 2);
    }

    if (!(cin >> h2.age >> h2.id)) return 0;
    cin >> ws;
    getline(cin, h2.name);
    if (h2.name.size() && h2.name.front() == '"') {
        if (h2.name.back() != '"') {
            string rest;
            while (getline(cin, rest)) {
                h2.name += "\n" + rest;
                if (!rest.empty() && rest.back() == '"') break;
            }
        }
        if (h2.name.size() >= 2 && h2.name.front() == '"' && h2.name.back() == '"')
            h2.name = h2.name.substr(1, h2.name.size() - 2);
    }

    int s1 = 0, s2 = 0;

    if (h1.name > h2.name) { s1 += 2; }
    else if (h2.name > h1.name) { s2 += 2; }

    if (isPrime(h1.age)) s1 += 4;
    if (isPrime(h2.age)) s2 += 4;

    if (isPerfectSquare(h1.id)) s1 += 3;
    if (isPerfectSquare(h2.id)) s2 += 3;

    if (s1 == s2) {
        cout << "CInCABECAS EMPATADOS";
    } else if (s1 > s2) {
        cout << h1.name << " WINS";
    } else {
        cout << h2.name << " WINS";
    }
    return 0;
}