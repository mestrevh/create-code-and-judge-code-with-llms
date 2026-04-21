/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline string trim(const string& s) {
    size_t a = 0, b = s.size();
    while (a < b && isspace((unsigned char)s[a])) a++;
    while (b > a && isspace((unsigned char)s[b-1])) b--;
    return s.substr(a, b-a);
}

static inline pair<string,string> splitByFirstDash(const string& line) {
    size_t p = line.find('-');
    if (p == string::npos) return {trim(line), ""};
    string left = trim(line.substr(0, p));
    string right = trim(line.substr(p+1));
    return {left, right};
}

static inline string normalizeCantor(const string& s) {
    string t = trim(s);
    if (!t.empty() && t.back() == '\r') t.pop_back();
    return t;
}

struct Item {
    string cantor;
    string genero;
    string key() const { return cantor + " " + genero; }
};

static bool cmpOut(const Item& a, const Item& b) {
    return a.cantor + " " + a.genero < b.cantor + " " + b.genero;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int I;
    if (!(cin >> I)) return 0;

    vector<Item> cds, caps;
    cds.reserve(I);
    caps.reserve(I);

    string line;
    getline(cin, line);

    for (int i = 0; i < I; i++) {
        getline(cin, line);
        line = trim(line);
        auto pr = splitByFirstDash(line);
        Item it;
        it.cantor = normalizeCantor(pr.first);
        it.genero = trim(pr.second);
        cds.push_back(it);
    }

    for (int i = 0; i < I; i++) {
        getline(cin, line);
        line = trim(line);
        auto pr = splitByFirstDash(line);
        Item it;
        it.cantor = normalizeCantor(pr.first);
        it.genero = trim(pr.second);
        caps.push_back(it);
    }

    vector<Item> cdsMatched;
    cdsMatched.reserve(I);

    map<string, vector<string>> capGenresByCantor;
    for (auto &cap : caps) capGenresByCantor[cap.cantor].push_back(cap.genero);

    unordered_map<string,int> capCount;
    capCount.reserve(caps.size()*2+1);
    for (auto &cap : caps) capCount[cap.cantor + " " + cap.genero]++;

    vector<Item> leftoverCDs;
    leftoverCDs.reserve(I);

    for (auto &cd : cds) {
        string k = cd.cantor + " + cd.genero;
        auto it = capCount.find(k);
        if (it != capCount.end() && it->second > 0) {
            it->second--;
            cdsMatched.push_back(cd);
        } else {
            leftoverCDs.push_back(cd);
        }
    }

    vector<Item> leftoverCaps;
    leftoverCaps.reserve(I);
    for (auto &cap : caps) {
        string k = cap.cantor + " " + cap.genero;
        auto it = capCount.find(k);
        if (it != capCount.end() && it->second > 0) {
            it->second--;
            leftoverCaps.push_back(cap);
        }
    }

    sort(cdsMatched.begin(), cdsMatched.end(), cmpOut);

    for (size_t i = 0; i < cdsMatched.size(); i++) {
        if (i) cout << "\n";
        cout << cdsMatched[i].cantor << " " << cdsMatched[i].genero;
    }

    if (!leftoverCDs.empty() || !leftoverCaps.empty()) {
        if (!cdsMatched.empty()) cout << "\n";
        cout << "Chandler, você vai ter que comprar a capa para os CDs:";
        vector<string> needCaps;
        needCaps.reserve(leftoverCDs.size());
        for (auto &cd : leftoverCDs) needCaps.push_back(cd.cantor);
        sort(needCaps.begin(), needCaps.end());
        needCaps.erase(unique(needCaps.begin(), needCaps.end()), needCaps.end());

        if (!needCaps.empty()) {
            cout << " ";
            for (size_t i = 0; i < needCaps.size(); i++) {
                if (i) cout << ", ";
                cout << needCaps[i];
            }
        }

        if (!leftoverCaps.empty()) {
            cout << ". E os CDs para as capas:";
            vector<string> needCDs;
            needCDs.reserve(leftoverCaps.size());
            for (auto &cap : leftoverCaps) needCDs.push_back(cap.cantor);
            sort(needCDs.begin(), needCDs.end());
            needCDs.erase(unique(needCDs.begin(), needCDs.end()), needCDs.end());

            if (!needCDs.empty()) {
                cout << " ";
                for (size_t i = 0; i < needCDs.size(); i++) {
                    if (i) cout << ", ";
                    cout << needCDs[i];
                }
            }
        }
        cout << ".";
    }

    return 0;
}