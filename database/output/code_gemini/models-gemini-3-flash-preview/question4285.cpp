/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string to_lower(string s) {
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (char)(s[i] + 32);
        }
    }
    return s;
}

bool endsWith(const string& s, const string& suffix) {
    if (s.length() < suffix.length()) return false;
    return s.compare(s.length() - suffix.length(), suffix.length(), suffix) == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> words;
    string s;
    while (cin >> s && s != "fim") {
        words.push_back(to_lower(s));
    }

    if (words.empty()) {
        cout << "Programa finalizado, você digitou apenas a palavra *fim*, desejando encerrar o programa." << endl;
        return 0;
    }

    vector<string> ger, par, inf, oth;
    for (const string& w : words) {
        if (endsWith(w, "ndo")) {
            ger.push_back(w);
        } else if (endsWith(w, "ado") || endsWith(w, "ido")) {
            par.push_back(w);
        } else if (endsWith(w, "ar") || endsWith(w, "er") || endsWith(w, "ir") || endsWith(w, "or")) {
            inf.push_back(w);
        } else {
            oth.push_back(w);
        }
    }

    if (ger.empty()) {
        cout << "Você não digitou nenhuma palavra no forma nominal!" << endl;
    } else {
        cout << "As palavras que você digitou no gerúndio foram as seguintes: ";
        for (size_t i = 0; i < ger.size(); ++i) {
            cout << ger[i] << (i == ger.size() - 1 ? "." : ", ");
        }
        cout << endl;
    }

    if (par.empty()) {
        cout << "Você não digitou nenhuma palavra no forma nominal!" << endl;
    } else {
        cout << "As palavras que você digitou estão no particípio: ";
        for (size_t i = 0; i < par.size(); ++i) {
            cout << par[i] << (i == par.size() - 1 ? "." : ", ");
        }
        cout << endl;
    }

    if (inf.empty()) {
        cout << "Você não digitou nenhuma palavra no forma nominal!" << endl;
    } else {
        cout << "As palavras que você digitou no infinitivo são: ";
        for (size_t i = 0; i < inf.size(); ++i) {
            cout << inf[i] << (i == inf.size() - 1 ? "." : ", ");
        }
        cout << endl;
    }

    if (!oth.empty()) {
        cout << "As palavras que você digitou que não estão no gerúndio, particípio ou infinitivo e/são: ";
        for (size_t i = 0; i < oth.size(); ++i) {
            cout << oth[i] << (i == oth.size() - 1 ? "." : ", ");
        }
        cout << endl;
    }

    return 0;
}