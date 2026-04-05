/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Item {
    long long qty = 0;
    long long value_cents = 0;
};

static long long parseMoneyToCents(const string& s) {
    bool neg = false;
    string t = s;
    if (!t.empty() && t[0] == '-') { neg = true; t = t.substr(1); }
    long long reais = 0, centavos = 0;
    size_t pos = t.find('.');
    if (pos == string::npos) {
        reais = stoll(t);
        centavos = 0;
    } else {
        string a = t.substr(0, pos);
        string b = t.substr(pos + 1);
        if (!a.empty()) reais = stoll(a); else reais = 0;
        if (b.size() >= 1) centavos += (b[0] - '0') * 10;
        if (b.size() >= 2) centavos += (b[1] - '0');
    }
    long long res = reais * 100 + centavos;
    return neg ? -res : res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, Item> items;
    unordered_map<long long, long long> totalQtyPerValueCents;
    long long total_cents = 0;

    string line;
    while (true) {
        string cmd;
        if (!(cin >> cmd)) break;

        if (cmd == "INSERIR") {
            string name;
            string xs, qs;
            cin >> name >> xs >> qs;
            long long value = parseMoneyToCents(xs);
            long long q = stoll(qs);

            auto it = items.find(name);
            if (it == items.end()) {
                items[name] = {q, value};
                total_cents += value * q;
                totalQtyPerValueCents[value] += q;
            } else {
                if (it->second.value_cents != value) {
                    long long oldValue = it->second.value_cents;
                    long long oldQty = it->second.qty;
                    total_cents -= oldValue * oldQty;
                    totalQtyPerValueCents[oldValue] -= oldQty;

                    it->second.value_cents = value;
                    it->second.qty = q;
                    total_cents += value * q;
                    totalQtyPerValueCents[value] += q;
                } else {
                    it->second.qty += q;
                    total_cents += value * q;
                    totalQtyPerValueCents[value] += q;
                }
            }
        } else if (cmd == "REMOVER") {
            string name;
            string qs;
            cin >> name >> qs;
            long long q = stoll(qs);
            auto it = items.find(name);
            if (it != items.end()) {
                long long removed = min(q, it->second.qty);
                it->second.qty -= removed;
                total_cents -= it->second.value_cents * removed;
                totalQtyPerValueCents[it->second.value_cents] -= removed;
                if (it->second.qty == 0) items.erase(it);
            }
        } else if (cmd == "REMOVERGRUPO") {
            string xs;
            cin >> xs;
            long long value = parseMoneyToCents(xs);
            auto qit = totalQtyPerValueCents.find(value);
            long long q = (qit == totalQtyPerValueCents.end() ? 0 : qit->second);
            if (q > 0) {
                vector<string> toErase;
                for (auto &p : items) {
                    if (p.second.value_cents == value) {
                        toErase.push_back(p.first);
                    }
                }
                for (auto &name : toErase) {
                    auto it = items.find(name);
                    if (it == items.end()) continue;
                    long long qty = it->second.qty;
                    total_cents -= value * qty;
                    totalQtyPerValueCents[value] -= qty;
                    items.erase(it);
                }
                if (totalQtyPerValueCents[value] == 0) totalQtyPerValueCents.erase(value);
            }
        } else if (cmd == "CONSULTAR") {
            long long absCents = llabs(total_cents);
            long long reais = absCents / 100;
            long long cents = absCents % 100;
            if (total_cents < 0) cout << "Atualmente a lista esta em R$-" << reais << "." << setw(1) << setfill('0') << (cents / 10) << "\n";
            else cout << "Atualmente a lista esta em R$" << reais << "." << setw(1) << setfill('0') << (cents / 10) << "\n";
            cout << "\n";
        } else if (cmd == "PROCURAR") {
            string name;
            cin >> name;
            auto it = items.find(name);
            if (it == items.end()) {
                cout << "Nome nao foi encontrado\n\n";
            } else {
                long long v = it->second.value_cents;
                long long absCents = llabs(v);
                long long reais = absCents / 100;
                long long cents = absCents % 100;
                if (v < 0) cout << "Nome - Valor - Quantidade: " << name << " - R$-" << reais << "." << (cents / 10) << " - " << it->second.qty << "\n\n";
                else cout << "Nome - Valor - Quantidade: " << name << " - R$" << reais << "." << (cents / 10) << " - " << it->second.qty << "\n\n";
            }
        }
    }

    return 0;
}