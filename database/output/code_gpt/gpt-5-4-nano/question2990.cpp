/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline string trim(const string& s) {
    size_t i = 0, j = s.size();
    while (i < j && isspace((unsigned char)s[i])) i++;
    while (j > i && isspace((unsigned char)s[j - 1])) j--;
    return s.substr(i, j - i);
}

static inline bool isDashLine(const string& line) {
    for (char c : line) if (c != '-') return false;
    return !line.empty();
}

static inline bool isNumberOnly(const string& s) {
    if (s.empty()) return false;
    size_t i = 0;
    if (s[0] == '-' || s[0] == '+') i = 1;
    if (i >= s.size()) return false;
    for (; i < s.size(); i++) if (!isdigit((unsigned char)s[i])) return false;
    return true;
}

struct Adventure {
    string name;
    string regen;
    string local;
    string year;
    vector<string> amigos;
    vector<string> inimigos;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Adventure> advs;
    string line;

    while (true) {
        if (!std::getline(cin, line)) return 0;
        line = trim(line);
        if (line.empty()) continue;
        if (isDashLine(line)) break;

        string N = line;

        string R, L, A;
        if (!getline(cin, R)) return 0;
        if (!getline(cin, L)) return 0;
        if (!getline(cin, A)) return 0;

        R = trim(R);
        L = trim(L);
        A = trim(A);

        vector<string> amigos, inimigos;

        if (!getline(cin, line)) return 0;
        string tag1 = trim(line);

        while (true) {
            if (!getline(cin, line)) return 0;
            line = trim(line);
            if (line == "FIM") break;
            if (!line.empty()) amigos.push_back(line);
        }

        if (!getline(cin, line)) return 0;
        string tag2 = trim(line);

        while (true) {
            if (!getline(cin, line)) return 0;
            line = trim(line);
            if (line == "FIM") break;
            if (!line.empty()) inimigos.push_back(line);
        }

        Adventure ad;
        ad.name = N;
        ad.regen = R;
        ad.local = L;
        ad.year = A;
        ad.amigos = std::move(amigos);
        ad.inimigos = std::move(inimigos);
        advs.push_back(std::move(ad));
    }

    while (true) {
        string Bline;
        if (!getline(cin, Bline)) break;
        Bline = trim(Bline);
        if (Bline.empty()) continue;

        string Fline, Iline;
        if (!getline(cin, Fline)) break;
        if (!getline(cin, Iline)) break;
        Fline = trim(Fline);
        Iline = trim(Iline);

        vector<string> results;
        results.reserve(64);

        auto matchesAdventure = [&](const Adventure& ad) -> bool {
            if (Fline == "TODOS") return true;
            if (Fline == "Aventura") return ad.name == Iline;
            if (Fline == "Doctor") return ad.regen == Iline;
            if (Fline == "Local") return ad.local == Iline;
            if (Fline == "Ano") return ad.year == Iline;
            if (Fline == "Amigo") {
                for (auto &x : ad.amigos) if (x == Iline) return true;
                return false;
            }
            if (Fline == "Inimigo") {
                for (auto &x : ad.inimigos) if (x == Iline) return true;
                return false;
            }
            return false;
        };

        if (Bline == "Aventura") {
            for (auto &ad : advs) if (matchesAdventure(ad)) results.push_back(ad.name);
        } else if (Bline == "Doctor") {
            for (auto &ad : advs) if (matchesAdventure(ad)) results.push_back(ad.regen);
        } else if (Bline == "Local") {
            for (auto &ad : advs) if (matchesAdventure(ad)) results.push_back(ad.local);
        } else if (Bline == "Ano") {
            for (auto &ad : advs) if (matchesAdventure(ad)) results.push_back(ad.year);
        } else if (Bline == "Amigo") {
            for (auto &ad : advs) if (matchesAdventure(ad)) for (auto &x : ad.amigos) results.push_back(x);
        } else if (Bline == "Inimigo") {
            for (auto &ad : advs) if (matchesAdventure(ad)) for (auto &x : ad.inimigos) results.push_back(x);
        }

        if (results.empty()) {
            cout << "Nao foi possivel encontrar nada com esses parametros.\n\n";
        } else {
            for (auto &s : results) cout << s << "\n";
            cout << "\n";
        }
    }

    return 0;
}