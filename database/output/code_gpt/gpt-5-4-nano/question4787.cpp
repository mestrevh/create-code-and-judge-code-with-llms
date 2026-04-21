/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Pokemon {
    string name;
    string type;
    long long power;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Pokemon> ps;
    string name, type;
    long long power;

    while (cin >> name >> type >> power) {
        ps.push_back({name, type, power});
    }

    if (ps.empty()) return 0;

    string orderTypes[] = {"fogo", "agua", "planta", "eletrico", "dragao"};
    unordered_map<string, long long> cnt;
    long long totalPower = 0;
    for (auto &p : ps) {
        cnt[p.type]++;
        totalPower += p.power;
    }

    string resType;
    long long bestCount = -1;
    for (auto &t : orderTypes) {
        auto it = cnt.find(t);
        if (it != cnt.end()) {
            if (it->second > bestCount) {
                bestCount = it->second;
                resType = t;
            }
        }
    }
    if (bestCount == -1) resType = ps[0].type;

    vector<long long> contribSizes;
    contribSizes.reserve(ps.size());
    long long maxLen = 0;
    for (auto &p : ps) maxLen = max<long long>(maxLen, p.name.size());
    long long totalNameLen = 0;

    for (auto &p : ps) {
        long long len = (long long)p.name.size();
        long long letters = 1;
        if (totalPower > 0) {
            long long val = (p.power * (long long)maxLen) / totalPower;
            letters = max(1LL, val);
        } else {
            letters = 1;
        }
        contribSizes.push_back(letters);
        totalNameLen += letters;
    }

    string resName;
    resName.reserve((size_t)totalNameLen);

    long long globalIdx = 0;
    for (size_t i = 0; i < ps.size(); i++) {
        const string &nm = ps[i].name;
        long long letters = contribSizes[i];
        if (nm.empty()) continue;
        for (long long k = 0; k < letters; k++) {
            resName.push_back(nm[(globalIdx + k < (long long)nm.size()) ? (globalIdx + k) : (long long)nm.size() - 1]);
        }
        globalIdx += letters;
    }

    long long resPower = totalPower;

    cout << "Nome: " << resName << "\n";
    cout << "Tipo: " << resType << "\n";
    cout << "Poder: " << resPower << "\n";

    return 0;
}