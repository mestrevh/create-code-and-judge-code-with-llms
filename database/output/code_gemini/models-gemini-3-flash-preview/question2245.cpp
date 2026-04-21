/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

struct Competitor {
    string name;
    bool failed;
    long long total_dist;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Competitor> players(3);
    players[0].name = "Mario";
    players[1].name = "Yoshi";
    players[2].name = "Toad";

    for (int i = 0; i < 3; ++i) {
        players[i].failed = false;
        players[i].total_dist = 0;
        string c[4];
        int d[4];
        for (int j = 0; j < 4; ++j) {
            cin >> c[j] >> d[j];
            players[i].total_dist += d[j];
        }

        if ((c[0] == "Esquerda" && c[1] == "Esquerda" && c[2] == "Esquerda") ||
            (c[1] == "Esquerda" && c[2] == "Esquerda" && c[3] == "Esquerda")) {
            players[i].failed = true;
        }
    }

    long long min_dist = LLONG_MAX;
    int winner_idx = -1;

    for (int i = 0; i < 3; ++i) {
        if (players[i].failed) {
            cout << players[i].name << " caiu em um buraco negro." << endl;
        } else {
            if (players[i].total_dist < min_dist) {
                min_dist = players[i].total_dist;
                winner_idx = i;
            }
        }
    }

    if (winner_idx != -1) {
        cout << players[winner_idx].name << " venceu a corrida!" << endl;
    }

    return 0;
}

