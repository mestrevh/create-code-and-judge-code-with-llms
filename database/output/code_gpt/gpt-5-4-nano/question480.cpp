/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string toLowerStr(string s) {
    for (char &c : s) c = (char)tolower((unsigned char)c);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sexo;
    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    long long homensCorte = 0, homensBarba = 0;
    long double faturamento = 0.0L;

    auto price = [&](const string& serv) -> long double {
        string s = toLowerStr(serv);
        if (s == "corte") return 25.0L;
        if (s == "barba") return 15.0L;
        if (s == "maquiagem") return 70.0L;
        if (s == "penteado") return 50.0L;
        return 0.0L;
    };

    while (true) {
        if (!getline(cin, sexo)) break;
        if (sexo.size() == 0) continue;
        string ssexo = toLowerStr(sexo);
        char c = ssexo[0];
        if (c != 'm' && c != 'f') break;

        string serv;
        if (!getline(cin, serv)) break;
        long double p = price(serv);
        faturamento += p;

        string sserv = toLowerStr(serv);
        if (c == 'm') {
            if (sserv == "corte") homensCorte++;
            else if (sserv == "barba") homensBarba++;
        }
    }

    if (homensCorte > homensBarba) cout << "CORTE\n";
    else if (homensBarba > homensCorte) cout << "BARBA\n";
    else cout << "AMBOS\n";

    cout << (double)faturamento << "\n";
    return 0;
}