/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> gerundio, particípio, infinitivo, nenhum;
    string s;
    bool onlyFim = false;

    if (!(cin >> s)) return 0;
    if (s == "fim") onlyFim = true;

    while (!onlyFim) {
        string lower = s;
        for (char &c : lower) c = (char)tolower((unsigned char)c);

        auto ends_with = [&](const string& suf) -> bool {
            if (lower.size() < suf.size()) return false;
            return equal(suf.rbegin(), suf.rend(), lower.rbegin());
        };

        bool g = false, p = false, i = false;

        if (ends_with("ando") || ends_with("endo") || ends_with("indo") || ends_with("indo")) g = true;
        if (ends_with("ado") || ends_with("ido") || ends_with("ada") || ends_with("ida")) p = true;
        if (ends_with("ar") || ends_with("er") || ends_with("ir")) i = true;

        if (g && !p) gerundio.push_back(s);
        else if (p && !g) particípio.push_back(s);
        else if (i && !g && !p) infinitivo.push_back(s);
        else if (i && p && !g) particípio.push_back(s);
        else if (i && g && !p) gerundio.push_back(s);
        else if (g && p) gerundio.push_back(s);
        else if (i) infinitivo.push_back(s);
        else nenhum.push_back(s);

        if (!(cin >> s)) break;
        if (s == "fim") break;
    }

    if (onlyFim) {
        cout << "Programa finalizado, você digitou apenas a palavra fim, desejando encerrar o programa.";
        return 0;
    }

    bool any = !(gerundio.empty() && particípio.empty() && infinitivo.empty());

    if (!any) {
        cout << "Você não digitou nenhuma palavra no forma nominal!";
        return 0;
    }

    cout << "As palavras que você digitou no gerúndio foram as seguintes:";
    if (gerundio.empty()) cout << " ";
    else {
        cout << " ";
        for (size_t k = 0; k < gerundio.size(); k++) {
            if (k) cout << ", ";
            string t = gerundio[k];
            for (char &c : t) c = (char)tolower((unsigned char)c);
            if (k == 0) cout << gerundio[k];
            else cout << gerundio[k];
        }
        cout << ".";
    }
    if (gerundio.empty()) cout << ".";
    cout << "\n";

    cout << "As palavras que você digitou estão no particípio:";
    if (particípio.empty()) cout << " ";
    else {
        cout << " ";
        for (size_t k = 0; k < particípio.size(); k++) {
            if (k) cout << ", ";
            cout << particípio[k];
        }
        cout << ".";
    }
    if (particípio.empty()) cout << ".";
    cout << "\n";

    cout << "As palavras que você digitou no infinitivo são:";
    if (infinitivo.empty()) cout << " ";
    else {
        cout << " ";
        for (size_t k = 0; k < infinitivo.size(); k++) {
            if (k) cout << ", ";
            cout << infinitivo[k];
        }
        cout << ".";
    }
    if (infinitivo.empty()) cout << ".";
    cout << "\n";

    if (!nenhum.empty()) {
        cout << "As palavras que você digitou que não estão no gerúndio, particípio ou infinitivo e/são:";
        cout << " ";
        for (size_t k = 0; k < nenhum.size(); k++) {
            if (k) cout << ", ";
            string t = nenhum[k];
            string tmp = t;
            for (char &c : tmp) c = (char)tolower((unsigned char)c);
            for (char &c : t) c = c;
            cout << t;
        }
        cout << ".";
    } else {
        cout << "As palavras que você digitou que não estão no gerúndio, particípio ou infinitivo e/são:";
        cout << " .";
    }

    return 0;
}