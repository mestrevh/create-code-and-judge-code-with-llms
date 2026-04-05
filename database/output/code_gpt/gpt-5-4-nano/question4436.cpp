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

    vector<string> names(N);
    vector<long long> unitCents(N), qty(N);
    vector<long long> lineTotals(N);

    for (int i = 0; i < N; i++) {
        cin >> names[i];
        string v;
        cin >> v;
        long long q;
        cin >> q;
        qty[i] = q;

        size_t pos = v.find('.');
        long long cents = 0;
        if (pos == string::npos) {
            cents = stoll(v) * 100;
        } else {
            long long reais = stoll(v.substr(0, pos));
            string frac = v.substr(pos + 1);
            if (frac.size() == 0) frac = "0";
            if (frac.size() == 1) frac.push_back('0');
            if (frac.size() > 2) frac = frac.substr(0, 2);
            cents = reais * 100 + stoll(frac);
        }
        unitCents[i] = cents;
        lineTotals[i] = unitCents[i] * qty[i];
    }

    string dummy;
    string dia;
    string reaisPrefix;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, dummy);

    getline(cin, dia);
    regex reDate(R"(no dia\s+(\d{2}\/\d{2}))");
    smatch m;
    string dateStr;
    if (regex_search(dia, m, reDate)) dateStr = m[1];
    else {
        for (char &c : dia) if (c == '\r' || c == '\n') c = ' ';
        dateStr.clear();
        for (int i = 0; i + 4 < (int)dia.size(); i++) {
            if (isdigit(dia[i]) && isdigit(dia[i+1]) && dia[i+2]=='/' && isdigit(dia[i+3]) && isdigit(dia[i+4])) {
                dateStr = dia.substr(i, 5);
                break;
            }
        }
    }

    string line;
    getline(cin, line);
    regex reMoney(R"(R\$\s*([0-9]+(?:\.[0-9]+)?))");
    smatch mm;
    long long paidCents = 0;
    if (regex_search(line, mm, reMoney)) {
        string v = mm[1];
        size_t pos = v.find('.');
        long long cents = 0;
        if (pos == string::npos) cents = stoll(v) * 100;
        else {
            long long reais = stoll(v.substr(0, pos));
            string frac = v.substr(pos + 1);
            if (frac.size() == 0) frac = "0";
            if (frac.size() == 1) frac.push_back('0');
            if (frac.size() > 2) frac = frac.substr(0, 2);
            cents = reais * 100 + stoll(frac);
        }
        paidCents = cents;
    } else {
        regex reAlt(R"(com\s+R\$\s*([0-9]+(?:\.[0-9]+)?))");
        if (regex_search(line, mm, reAlt)) {
            string v = mm[1];
            size_t pos = v.find('.');
            long long cents = 0;
            if (pos == string::npos) cents = stoll(v) * 100;
            else {
                long long reais = stoll(v.substr(0, pos));
                string frac = v.substr(pos + 1);
                if (frac.size() == 0) frac = "0";
                if (frac.size() == 1) frac.push_back('0');
                if (frac.size() > 2) frac = frac.substr(0, 2);
                cents = reais * 100 + stoll(frac);
            }
            paidCents = cents;
        }
    }

    auto formatMoney = [](long long cents) -> string {
        bool neg = cents < 0;
        if (neg) cents = -cents;
        long long reais = cents / 100;
        long long c = cents % 100;
        ostringstream oss;
        if (neg) oss << "-";
        oss << "R$" << reais << "." << setw(2) << setfill('0') << c;
        return oss.str();
    };

    long long totalCents = 0;
    for (int i = 0; i < N; i++) totalCents += lineTotals[i];
    long long trocoCents = paidCents - totalCents;

    const string header = "=============";
    cout << header << "\n";
    cout << "NF - 0123\n";
    cout << "Data - " << dateStr << "\n";
    cout << header << "\n";

    for (int i = 0; i < N; i++) {
        cout << qty[i] << "x " << names[i] << " - " << formatMoney(lineTotals[i]) << "\n";
    }

    cout << "\n";
    cout << "Valor Total - " << formatMoney(totalCents) << "\n";
    cout << "Pago - " << formatMoney(paidCents) << "\n";
    cout << "Troco - " << formatMoney(trocoCents) << "\n";
    cout << header;

    return 0;
}