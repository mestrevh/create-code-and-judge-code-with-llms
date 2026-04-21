/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string trim(const string& s) {
    size_t a = 0, b = s.size();
    while (a < b && isspace((unsigned char)s[a])) a++;
    while (b > a && isspace((unsigned char)s[b-1])) b--;
    return s.substr(a, b - a);
}

static string toUpperUnicodeSafe(string s) {
    for (char &c : s) {
        c = (char)toupper((unsigned char)c);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string tipo, desc;
    if (!getline(cin, tipo)) return 0;
    if (!getline(cin, desc)) return 0;

    tipo = toUpperUnicodeSafe(trim(tipo));
    desc = toUpperUnicodeSafe(trim(desc));

    double ternos[] = {0, 0, 0};
    double total = 0.0;

    if (tipo.find("TERNO") != string::npos) {
        double base = 0.0;
        if (desc.find("SIMPLES") != string::npos) base = 120.40;
        else if (desc.find("COMPLETO") != string::npos) base = 150.35;
        else if (desc.find("FRAQUE") != string::npos) base = 180.70;
        total = base * 0.93;
    } else {
        double base = 0.0;
        if (desc.find("GRAVATA") != string::npos) base = 30.00;
        else if (desc.find("SAPATO") != string::npos) base = 80.00;
        else if (desc.find("CINTO") != string::npos) base = 15.00;
        total = base;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << total << "\n";
    return 0;
}