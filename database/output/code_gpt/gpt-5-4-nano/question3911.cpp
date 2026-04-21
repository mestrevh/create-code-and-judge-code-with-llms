/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1;
    string s;
    while ((int)s.size() < 7 && cin >> ws && !cin.eof()) {
        char c = (char)cin.get();
        if (cin.eof()) break;
        if (c == '\n' || c == '\r' || c == '\t') continue;
        s.push_back(c);
    }
    if ((int)s.size() < 7) {
        while ((int)s.size() < 7 && cin) {
            char c;
            if (!(cin >> c)) break;
            s.push_back(c);
        }
    }
    if ((int)s.size() != 7) {
        return 0;
    }

    string ing = s;
    vector<char> items;
    for (int i = 0; i < 6; i++) items.push_back(ing[i+1]);

    char first = items[0];
    char last = items[5];

    bool hasValidLogic = true;
    bool badSauce = false;

    auto isSpace = [&](char c){ return c == ' '; };

    if (isSpace(first) || isSpace(last) || !((first=='.' || first==':') && (last=='.' || last==':') && first==last)) {
        hasValidLogic = false;
    }

    char meat = 0;
    int meatCount = 0;
    for (char c : items) {
        if (c=='b' || c=='f' || c=='p') {
            meat = c;
            meatCount++;
        }
    }
    if (meatCount > 1) hasValidLogic = false;

    bool allowedExtra = true;
    int extraCount = 0;
    for (int i = 1; i <= 4; i++) {
        char c = items[i];
        if (c=='.' || c==':' || c=='b' || c=='f' || c=='p' || c==' ') {
            if (c!=' ') allowedExtra = false;
        } else if (c=='A' || c=='T' || c=='C' || c=='R') {
            extraCount++;
        } else if (c=='P' || c=='D' || c=='M' || c=='E') {
        } else {
            if (c!=' ') allowedExtra = false;
        }
    }
    if (!allowedExtra) hasValidLogic = false;
    if (extraCount > 3) hasValidLogic = false;

    auto isSauce = [&](char c){ return c=='P' || c=='D' || c=='M' || c=='E'; };
    vector<char> sauces;
    for (int i = 0; i < 6; i++) if (isSauce(items[i])) sauces.push_back(items[i]);

    if ((int)sauces.size() != 1 || sauces[0] != 'P') badSauce = true;

    bool extraOnInvalidPositions = false;
    if (meatCount == 1) {
        int meatPos = -1;
        for (int i = 0; i < 6; i++) if (items[i]==meat) { meatPos=i; break; }
        for (int i = 0; i < meatPos; i++) {
            char c = items[i];
            if (c=='A' || c=='T' || c=='C' || c=='R') extraOnInvalidPositions = true;
        }
        for (int i = meatPos+1; i < 6; i++) {
            char c = items[i];
            if (c=='.' || c==':' || c=='b' || c=='f' || c=='p') extraOnInvalidPositions = true;
        }
    } else {
        for (int i = 1; i < 5; i++) {
            char c = items[i];
            if (c=='A' || c=='T' || c=='C' || c=='R') {
                if (i == 1 || i == 2 || i == 3 || i == 4) {
                }
            } else if (c!=' ') {
                if (!(c=='A' || c=='T' || c=='C' || c=='R')) {
                }
            }
        }
    }

    if (extraOnInvalidPositions) hasValidLogic = false;

    if (hasValidLogic && !badSauce) {
        cout << "Valido\n";
    } else {
        cout << "Invalido\n";
        if (badSauce) cout << "...Mas pelo menos ganhou um chute\n";
    }

    return 0;
}