/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C;
    if (!(cin >> A >> B >> C)) return 0;

    vector<string> ops = {"Quadrado","Resto","Multi","Div","Soma","Sub"};
    auto sq = [&]() -> long long { return A * A; };
    auto resto = [&]() -> long long { 
        if (B == 0) return LLONG_MIN;
        return A % B; 
    };
    auto multi = [&]() -> long long { return A * B; };
    auto divv = [&]() -> long long { 
        if (B == 0) return LLONG_MIN;
        return A / B; 
    };
    auto soma = [&]() -> long long { return A + B; };
    auto sub = [&]() -> long long { return A - B; };

    vector<pair<string, function<long long()>>> funcs;
    funcs.push_back({"Quadrado", sq});
    funcs.push_back({"Resto", resto});
    funcs.push_back({"Multi", multi});
    funcs.push_back({"Div", divv});
    funcs.push_back({"Soma", soma});
    funcs.push_back({"Sub", sub});

    vector<int> matches;
    int start = 0;
    bool found = false;

    for (int i = 0; i < (int)funcs.size(); i++) {
        long long val = funcs[i].second();
        if (val == C) {
            matches.push_back(i);
        }
    }

    if (matches.empty()) {
        cout << "Impossivel vitores\n";
        return 0;
    }

    start = matches[0];
    cout << funcs[start].first << " Vitoris\n";
    for (int k = start + 1; k < (int)funcs.size(); k++) {
        long long val = funcs[k].second();
        if (val == C) cout << "tambem " << funcs[k].first << "\n";
    }

    return 0;
}