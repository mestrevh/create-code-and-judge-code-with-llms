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

bool cmp(const Player &a, const Player &b) {
    return a.skill > b.skill;
}

int main() {
    int N, T;
    cin >> N >> T;
    vector<Player> players(N);
    for(int i = 0; i < N; ++i) {
        cin >> players[i].name >> players[i].skill;
    }
    sort(players.begin(), players.end(), cmp);

    vector<vector<string>> teams(T);
    int pick = 0, dir = 1;
    for(int i = 0; i < N; ++i) {
        teams[pick].push_back(players[i].name);
        pick += dir;
        if(pick == T) {
            pick = T-1;
            dir = -1;
        }
        if(pick == -1) {
            pick = 0;
            dir = 1;
        }
    }

    for(int i = 0; i < T; ++i) {
        cout << "Time " << (i+1) << endl;
        sort(teams[i].begin(), teams[i].end());
        for(const string &name : teams[i]) {
            cout << name << endl;
        }
        cout << endl;
    }
    return 0;
}
