/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string trim(const string& s) {
    size_t b = s.find_first_not_of(" \t\r\n");
    if (b == string::npos) return "";
    size_t e = s.find_last_not_of(" \t\r\n");
    return s.substr(b, e - b + 1);
}

static string normDate(const string& s) {
    string t = trim(s);
    for (char &c : t) if (c == '-') c = '/';
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> rgStatus(N), rgDate(N), passStatus(N), passDate(N), seat(N);

    for (int i = 0; i < N; i++) {
        cin >> rgStatus[i];
        cin >> rgDate[i];
        cin >> passStatus[i];
        cin >> passDate[i];
        cin >> seat[i];
    }

    for (int i = 0; i < N; i++) {
        if (rgStatus[i] != "RG") {
            cout << "a saida e nessa direcao\n";
            continue;
        }
        if (passStatus[i] != "Passagem") {
            cout << "a recepçao e nessa direcao\n";
            continue;
        }
        if (normDate(rgDate[i]) != normDate(passDate[i])) {
            cout << "190\n";
            continue;
        }
        cout << "o seu assento e " << seat[i] << " tenha um bom dia\n";
    }

    return 0;
}