/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Country {
    string name;
    int gold = 0, silver = 0, bronze = 0;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, Country> mp;
    string line;

    while (getline(cin, line)) {
        if (line.size() && line[0] == '*' && line.find('*') != string::npos) break;

        size_t comma = line.find(',');
        if (comma == string::npos) continue;

        string country = line.substr(0, comma);
        string medal = line.substr(comma + 1);

        if (!mp.count(country)) {
            Country c;
            c.name = country;
            mp[country] = c;
        }

        if (medal == "ouro") mp[country].gold++;
        else if (medal == "prata") mp[country].silver++;
        else if (medal == "bronze") mp[country].bronze++;
    }

    vector<Country> v;
    v.reserve(mp.size());
    for (auto &p : mp) v.push_back(p.second);

    auto cmp = [](const Country& a, const Country& b) {
        if (a.gold != b.gold) return a.gold > b.gold;
        if (a.silver != b.silver) return a.silver > b.silver;
        return a.bronze > b.bronze;
    };
    sort(v.begin(), v.end(), cmp);

    for (size_t i = 0; i < v.size(); i++) {
        const auto &c = v[i];
        cout << (i + 1) << ")" << c.name << " ouro:" << c.gold
             << " prata:" << c.silver << " bronze:" << c.bronze;
        if (i + 1 < v.size()) cout << "\n";
    }

    return 0;
}