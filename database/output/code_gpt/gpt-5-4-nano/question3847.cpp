/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

string referencia(const string& nome) {
    vector<string> w;
    string cur;
    for (char c : nome) {
        if (isspace((unsigned char)c)) {
            if (!cur.empty()) {
                w.push_back(cur);
                cur.clear();
            }
        } else {
            cur.push_back(c);
        }
    }
    if (!cur.empty()) w.push_back(cur);
    if (w.empty()) return "";

    string sobrenome = w.back();
    size_t n = w.size();

    set<string> ignorar = {"de","do","da","das","dos","e"};
    vector<string> outras;
    for (size_t i = 0; i + 1 < n; i++) {
        if (ignorar.find(w[i]) != ignorar.end()) continue;
        outras.push_back(w[i]);
    }

    if (outras.empty()) {
        return sobrenome + ", " + "" + ".";
    }

    string resto;
    for (size_t i = 0; i < outras.size(); i++) {
        if (i) resto += ' ';
        resto += outras[i];
    }

    return sobrenome + ", " + resto + ".";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line, nome;
    bool first = true;
    while (getline(cin, line)) {
        if (!first) nome += "\n";
        nome += line;
        first = false;
    }
    if (nome.empty()) return 0;

    cout << referencia(nome) << "\n";
    return 0;
}