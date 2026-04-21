/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string normalize(const string& s) {
    string t;
    t.reserve(s.size());
    for (unsigned char ch : s) {
        char c = (char)ch;
        c = (char)tolower((unsigned char)c);
        if (c >= 'a' && c <= 'z') t.push_back(c);
        else if (c >= '0' && c <= '9') t.push_back(c);
        else if (c == ' ' || c == '-' || c == '_' ) t.push_back(' ');
        else {
            if ((unsigned char)c == 195 || (unsigned char)c == 227 || (unsigned char)c == 226 || (unsigned char)c == 174) {
            }
            else {
                t.push_back(' ');
            }
        }
    }
    string u;
    bool prevSpace = false;
    for (char c : t) {
        if (c == ' ') {
            if (!prevSpace) u.push_back(' ');
            prevSpace = true;
        } else {
            u.push_back(c);
            prevSpace = false;
        }
    }
    if (!u.empty() && u.front() == ' ') u.erase(u.begin());
    if (!u.empty() && u.back() == ' ') u.pop_back();
    return u;
}

static string stripAccentsAndNormalize(const string& input) {
    string s;
    s.reserve(input.size());
    for (size_t i = 0; i < input.size(); ) {
        unsigned char c = (unsigned char)input[i];
        if (c < 128) {
            char lc = (char)tolower((unsigned char)c);
            if (lc >= 'a' && lc <= 'z') s.push_back(lc);
            else if (lc >= '0' && lc <= '9') s.push_back(lc);
            else s.push_back(' ');
            i++;
        } else if ((unsigned char)input[i] == 195 && i + 1 < input.size()) {
            unsigned char c2 = (unsigned char)input[i + 1];
            char out = 0;
            if (c2 == 160 || c2 == 161) out = 'a';
            else if (c2 == 162 || c2 == 163) out = 'a';
            else if (c2 == 170 || c2 == 169 || c2 == 173 || c2 == 174) out = 'a';
            else if (c2 == 176) out = 'o';
            else if (c2 == 177) out = 'o';
            else if (c2 == 178 || c2 == 179) out = 'o';
            else if (c2 == 186 || c2 == 185) out = 'o';
            else if (c2 == 181) out = 'n';
            else if (c2 == 187 || c2 == 186) out = 'u';
            else if (c2 == 192 || c2 == 193) out = 'a';
            else if (c2 == 200 || c2 == 201) out = 'e';
            else if (c2 == 204 || c2 == 205) out = 'i';
            else if (c2 == 206 || c2 == 207) out = 'i';
            else if (c2 == 210 || c2 == 211) out = 'o';
            else if (c2 == 214 || c2 == 215) out = 'o';
            else if (c2 == 217 || c2 == 218) out = 'u';
            else if (c2 == 222 || c2 == 223) out = 's';
            else if (c2 == 199) out = 'c';
            else out = 0;

            if (out) s.push_back(out);
            else s.push_back(' ');
            i += 2;
        } else {
            i++;
            s.push_back(' ');
        }
    }

    bool prevSpace = false;
    string t;
    for (char c : s) {
        if (c == ' ') {
            if (!prevSpace) t.push_back(' ');
            prevSpace = true;
        } else {
            t.push_back(c);
            prevSpace = false;
        }
    }
    if (!t.empty() && t.front() == ' ') t.erase(t.begin());
    if (!t.empty() && t.back() == ' ') t.pop_back();
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string pacote, forma;
    if (!getline(cin, pacote)) return 0;
    if (!getline(cin, forma)) return 0;

    pacote = stripAccentsAndNormalize(pacote);
    forma = stripAccentsAndNormalize(forma);

    double basePrice = 0.0;
    int baseChannels = 0;

    if (pacote == "basico") {
        basePrice = 80.80;
        baseChannels = 32;
    } else if (pacote == "entretenimento") {
        basePrice = 100.40;
        baseChannels = 55;
    } else if (pacote == "multicultural") {
        basePrice = 130.23;
        baseChannels = 70;
    } else if (pacote == "completo") {
        basePrice = 215.50;
        baseChannels = 112;
    }

    bool isDebit = (forma == "debito automatico" || forma == "debito automati co" || forma == "debito automati co");
    if (!isDebit) {
        string f = forma;
        f.erase(remove(f.begin(), f.end(), ' '), f.end());
        string x = "debitoautomatico";
        if (f == x) isDebit = true;
    }

    double finalPrice = basePrice;
    int totalChannels = baseChannels;

    if (isDebit) {
        bool isSmall = (pacote == "basico" || pacote == "entretenimento");
        if (isSmall) {
            finalPrice = basePrice * 0.95;
            totalChannels += 6;
        } else {
            finalPrice = basePrice * 0.90;
            totalChannels += 11;
        }
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << finalPrice << "\n";
    cout << totalChannels << "\n";
    return 0;
}