/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Player {
    string name;
    int skill;
};

bool cmp(Player &a, Player &b) {
    return a.skill > b.skill;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;
    vector<Player> players(N);
    for (int i = 0; i < N; ++i) {
        cin >> players[i].name >> players[i].skill;
    }

    sort(players.begin(), players.end(), cmp);

    vector<vector<string>> teams(T); // teams[i] stores names in team i(0-based)

    int turn = 0;
    for (int i = 0; i < N; ++i) {
        teams[turn].push_back(players[i].name);
        turn = (turn + 1) % T;
    }

    for (int i = 0; i < T; ++i) {
        cout << "Time " << i + 1 << "\n";
        sort(teams[i].begin(), teams[i].end());
        for (string &name : teams[i]) {
            cout << name << "\n";
        }
        cout << "\n";
    }
    return 0;
}
