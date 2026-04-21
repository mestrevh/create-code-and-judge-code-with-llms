/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> teams(8);
    for (int i = 0; i < 8; i++) {
        string s;
        if (!getline(cin, s)) return 0;
        while (s.size() == 0) {
            if (!getline(cin, s)) return 0;
        }
        teams[i] = s[0];
    }

    auto getTeamByIndex = [&](int idx) -> char {
        return teams[idx];
    };

    vector<pair<int,int>> games(8);
    for (int i = 0; i < 4; i++) {
        int a,b;
        cin >> a >> b;
        games[i] = {a,b};
    }

    vector<char> q(4);
    for (int i = 0; i < 4; i++) cin >> q[i];

    vector<char> s(2);
    for (int i = 0; i < 2; i++) cin >> s[i];

    char f;
    cin >> f;

    vector<char> qWinners(4);
    for (int i = 0; i < 4; i++) {
        int first = games[i].first, second = games[i].second;
        qWinners[i] = (q[i] == 'A') ? getTeamByIndex(first) : getTeamByIndex(second);
    }

    vector<char> sWinners(2);
    for (int i = 0; i < 2; i++) {
        char first = qWinners[2*i];
        char second = qWinners[2*i+1];
        sWinners[i] = (s[i] == 'X') ? first : second;
    }

    char finalWinner;
    char finalFirst = sWinners[0];
    char finalSecond = sWinners[1];
    finalWinner = (f == '#') ? finalFirst : finalSecond;

    for (int i = 0; i < 4; i++) {
        cout << "Quartas de final " << (i+1) << ": "
             << getTeamByIndex(games[i].first) << " x " << getTeamByIndex(games[i].second) << "\n";
    }
    cout << "Semifinal 1: " << qWinners[0] << " x " << qWinners[1] << "\n";
    cout << "Semifinal 2: " << qWinners[2] << " x " << qWinners[3] << "\n";
    cout << "Final: " << sWinners[0] << " x " << sWinners[1] << "\n";
    cout << "O vencedor da competicao de futebol de robots foi " << finalWinner << "!\n";

    return 0;
}