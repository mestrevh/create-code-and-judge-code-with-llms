/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string P, A;
    long long L;
    if (!getline(cin, P)) return 0;
    if (!getline(cin, A)) return 0;
    string line;
    getline(cin, line);
    while (line.size() == 0 && cin.good()) {
        if (!getline(cin, line)) break;
    }
    if (line.size() == 0) return 0;
    stringstream ss(line);
    ss >> L;

    auto trim = [](string s) {
        size_t i = 0, j = s.size();
        while (i < j && isspace((unsigned char)s[i])) i++;
        while (j > i && isspace((unsigned char)s[j-1])) j--;
        return s.substr(i, j - i);
    };
    P = trim(P);
    A = trim(A);

    long long attackerLevel, attackerAttack;
    if (P == "Slowbro") {
        attackerLevel = 30;
        attackerAttack = 50;
    } else if (P == "Dragonite") {
        attackerLevel = 40;
        attackerAttack = 128;
    } else {
        cout << "Pokemon invalido\n";
        return 0;
    }

    long long power;
    if (A == "Surf") power = 90;
    else if (A == "Flamethrower") power = 90;
    else if (A == "Grass Knot") power = 120;
    else {
        cout << "Ataque invalido\n";
        return 0;
    }

    long long base = 90, IV = 9, EV = 25600;
    long long moltresBaseHP = 2 * base + IV + EV / 4;
    long long HP = (moltresBaseHP * L) / 100 + L + 10;

    long long defenseIV = 9, defenseEV = 25600, defenseBase = 90;
    long long D = ( (2 * defenseBase + defenseIV + defenseEV / 4) * L ) / 100 + L + 10;
    D = (D / 1); 

    auto modForAttack = [&](const string& atk) -> double {
        if (atk == "Surf") return 2.0;
        if (atk == "Flamethrower") return 0.5;
        if (atk == "Grass Knot") return 1.0;
        return 1.0;
    };

    double modifier = modForAttack(A);

    double dmg = 0.0;
    dmg = ( (2.0 * attackerLevel / 5.0 + 2.0) * (double)power * (double)attackerAttack / (double)D ) / 50.0 + 2.0;
    dmg *= modifier;

    long long finalHP = HP - (long long)floor(dmg * 4.0 + 1e-9);

    if (finalHP <= 0) cout << "Moltres morto\n";
    else if (finalHP < 10) cout << "Moltres capturado\n";
    else cout << "Moltres fugiu\n";
    return 0;
}