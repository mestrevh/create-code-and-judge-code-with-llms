/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Item {
    string nome;
    long long precoCents;
    int pref;
};

static long long parsePriceToCents(const string& s) {
    string t = s;
    bool neg = false;
    if (!t.empty() && t[0] == '-') { neg = true; t = t.substr(1); }
    size_t pos = t.find('.');
    string a = (pos == string::npos) ? t : t.substr(0, pos);
    string b = (pos == string::npos) ? "" : t.substr(pos + 1);
    long long reais = 0;
    if (!a.empty()) reais = stoll(a);
    while (b.size() < 2) b.push_back('0');
    if (b.size() > 2) b = b.substr(0, 2);
    long long cents = b.empty() ? 0 : stoll(b);
    long long res = reais * 100 + cents;
    return neg ? -res : res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string nome;
    while (true) {
        if (!(cin >> nome)) return 0;
        if (!nome.empty() && nome[0] == '*') break;
        int Q;
        cin >> Q;

        vector<Item> v;
        v.reserve(Q);

        for (int i = 0; i < Q; i++) {
            string obj;
            cin >> obj;
            string priceStr;
            cin >> priceStr;
            long long cents = parsePriceToCents(priceStr);
            int pref;
            cin >> pref;

            v.push_back({obj, cents, pref});
        }

        sort(v.begin(), v.end(), [](const Item& a, const Item& b) {
            if (a.pref != b.pref) return a.pref > b.pref;
            if (a.precoCents != b.precoCents) return a.precoCents < b.precoCents;
            return a.nome < b.nome;
        });

        cout << "Lista de " << nome << "\n";
        for (size_t i = 0; i < v.size(); i++) {
            long long cents = v[i].precoCents;
            if (cents < 0) cents = -cents;
            long long reais = cents / 100;
            long long cc = cents % 100;
            cout << v[i].nome << " - R$" << reais << "." << setw(2) << setfill('0') << cc << setfill(' ') << "\n";
        }
        cout << "\n";
    }

    return 0;
}