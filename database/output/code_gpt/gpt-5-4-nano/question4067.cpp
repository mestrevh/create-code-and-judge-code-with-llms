/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string enemyName, enemyType;
    long long enemyAttack, enemyDefense;
    if (!(cin >> enemyName >> enemyType >> enemyAttack >> enemyDefense)) return 0;

    int n;
    cin >> n;

    auto isEffective = [&](const string& myType, const string& otherType) -> bool {
        if (myType == "agua" && otherType == "fogo") return true;
        if (myType == "grama" && otherType == "agua") return true;
        if (myType == "fogo" && otherType == "grama") return true;
        return false;
    };

    struct Pokemon {
        string name, type;
        long long attack, defense;
        double factor;
    };

    vector<Pokemon> v;
    v.reserve(n);

    for (int i = 0; i < n; i++) {
        Pokemon p;
        cin >> p.name >> p.type >> p.attack >> p.defense;
        long long effectiveAttack = p.attack;
        if (isEffective(p.type, enemyType)) effectiveAttack = p.attack + p.attack / 2;
        p.factor = (double)effectiveAttack - (double)enemyDefense;
        v.push_back(p);
    }

    sort(v.begin(), v.end(), [&](const Pokemon& a, const Pokemon& b) {
        if (a.factor != b.factor) return a.factor > b.factor;
        return a.name < b.name;
    });

    for (int i = 0; i < (int)v.size(); i++) {
        cout << (i + 1) << ". " << v[i].name;
        if (i + 1 < (int)v.size()) cout << "\n";
    }
    return 0;
}