/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int I;
    if (!(cin >> I)) return 0;

    vector<string> allowed = {"Anitta", "Ludmilla", "Jojo", "Kevinho", "Livinho"};
    unordered_set<string> ok(allowed.begin(), allowed.end());

    unordered_map<string, int> cnt;
    for (auto &a : allowed) cnt[a] = 0;

    for (int i = 0; i < I; i++) {
        string s;
        cin >> s;
        if (ok.count(s)) cnt[s]++;
    }

    int best = 0;
    for (auto &a : allowed) best = max(best, cnt[a]);

    vector<string> bests;
    for (auto &a : allowed) if (cnt[a] == best && best > 0) bests.push_back(a);

    if (bests.empty()) {
        cout << "As pessoas querem ver outra pessoa\n";
    } else if (bests.size() == 1) {
        cout << "As pessoas estao esperando por " << bests[0] << ".\n";
    } else {
        sort(bests.begin(), bests.end());
        cout << "Houve um empate entre: ";
        for (size_t i = 0; i < bests.size(); i++) {
            if (i) cout << ", ";
            cout << bests[i];
        }
        cout << "\n";
    }

    return 0;
}