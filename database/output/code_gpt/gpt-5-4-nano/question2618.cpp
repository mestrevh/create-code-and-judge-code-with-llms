/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    struct Item {
        int A;
        long long cents;
    };

    vector<Item> v;
    v.reserve(N);

    for (int i = 0; i < N; i++) {
        int A;
        string ps;
        cin >> A >> ps;
        bool neg = false;
        if (!ps.empty() && ps[0] == '-') {
            neg = true;
            ps = ps.substr(1);
        }
        long long intPart = 0, fracPart = 0;
        size_t pos = ps.find('.');
        if (pos == string::npos) {
            intPart = stoll(ps);
            fracPart = 0;
        } else {
            string s1 = ps.substr(0, pos);
            string s2 = ps.substr(pos + 1);
            if (s1.empty()) intPart = 0;
            else intPart = stoll(s1);
            if (s2.size() >= 2) fracPart = stoll(s2.substr(0, 2));
            else if (s2.size() == 1) fracPart = stoll(s2) * 10;
            else fracPart = 0;
        }
        long long cents = intPart * 100 + fracPart;
        if (neg) cents = -cents;
        v.push_back({A, cents});
    }

    sort(v.begin(), v.end(), [](const Item& x, const Item& y) {
        if (x.A != y.A) return x.A > y.A;
        return x.cents < y.cents;
    });

    auto printCents = [&](long long cents) {
        if (cents < 0) {
            cout << '-';
            cents = -cents;
        }
        long long intPart = cents / 100;
        long long frac = cents % 100;
        cout << intPart << '.';
        if (frac < 10) cout << '0';
        cout << frac;
    };

    for (auto &it : v) {
        cout << "Nota: " << it.A << "\n";
        cout << "Preco: ";
        printCents(it.cents);
        cout << "\n\n";
    }

    return 0;
}