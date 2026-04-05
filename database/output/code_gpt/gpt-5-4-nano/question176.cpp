/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Player {
    string name;
    int h;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    if (!(cin >> N >> T)) return 0;

    vector<Player> players(N);
    for (int i = 0; i < N; i++) cin >> players[i].name >> players[i].h;

    sort(players.begin(), players.end(), [](const Player& a, const Player& b){
        return a.h > b.h;
    });

    vector<vector<string>> teams(T);
    for (int i = 0; i < N; i++) {
        teams[i % T].push_back(players[i].name);
    }

    for (int t = 0; t < T; t++) {
        sort(teams[t].begin(), teams[t].end());
        cout << "Time " << (t + 1) << "\n";
        for (auto &nm : teams[t]) cout << nm << "\n";
        cout << "\n";
    }
    return 0;
}