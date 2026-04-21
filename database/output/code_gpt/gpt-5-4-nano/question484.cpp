/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string normalize(const string& s) {
    string t;
    for (unsigned char c : s) t += (char)tolower(c);
    auto isspace2 = [](unsigned char ch){ return std::isspace(ch); };
    size_t l = 0, r = t.size();
    while (l < r && isspace2(t[l])) l++;
    while (r > l && isspace2(t[r-1])) r--;
    return t.substr(l, r-l);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string tipo;
    bool anyTigers = false;
    long double tigersSum = 0;
    long long tigersCnt = 0;

    long long monkeysCnt = 0;
    long long snakesVenezuelaCnt = 0;

    while (true) {
        if (!getline(cin, tipo)) break;
        if (tipo.size() == 0) continue;
        string tipoNorm = normalize(tipo);
        if (tipoNorm == "parar") break;

        string pesoStr, pais;
        if (!getline(cin, pesoStr)) break;
        if (!getline(cin, pais)) break;

        long double peso = 0;
        try {
            peso = stold(pesoStr);
        } catch (...) {
            peso = 0;
        }

        string paisNorm = normalize(pais);

        if (tipoNorm == "macaco") monkeysCnt++;
        if (tipoNorm == "tigre") {
            anyTigers = true;
            tigersSum += peso;
            tigersCnt++;
        }
        if (tipoNorm == "cobra" && paisNorm == "venezuela") snakesVenezuelaCnt++;

        string cont;
        if (!getline(cin, cont)) break;
        string contNorm = normalize(cont);
        if (contNorm == "parar") break;
        if (contNorm == "sair") {
            break;
        }
    }

    long double avgTiger = 0.0;
    if (tigersCnt > 0) avgTiger = tigersSum / (long double)tigersCnt;

    cout << monkeysCnt << "\n";
    cout.setf(std::ios::fixed);
    cout << setprecision(2) << (double)avgTiger << "\n";
    cout << snakesVenezuelaCnt << "\n";
    return 0;
}