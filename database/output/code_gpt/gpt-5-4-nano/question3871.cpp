/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Player {
    string name;
    string country;
    int atk, def, cost;
};

struct Club {
    string name;
    long long money;
    char focus;
    int order;
    vector<int> players; // indices of players
};

static bool isAttackOrDefender(const Player& p) {
    return p.atk >= p.def;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Club> clubs;
    clubs.reserve(N);

    int clubIdx = 0;
    for (int i = 0; i < N; i++) {
        string name;
        long long dinheiro;
        char foco;
        cin >> name;
        if (name == "Vasco") {
            string dummyName = name;
            cin >> dinheiro >> foco;
        } else {
            cin >> dinheiro >> foco;
            Club c;
            c.name = name;
            c.money = dinheiro;
            c.focus = foco;
            c.order = clubIdx++;
            clubs.push_back(std::move(c));
        }
    }

    int N2;
    cin >> N2;

    vector<Player> players(N2);
    for (int i = 0; i < N2; i++) {
        cin >> players[i].name >> players[i].country >> players[i].atk >> players[i].def >> players[i].cost;
    }

    for (const auto& p : players) {
        int best = -1;
        for (int i = 0; i < (int)clubs.size(); i++) {
            auto &c = clubs[i];
            if (c.money < p.cost) continue;

            bool playerIsAttack = (p.atk >= p.def);
            bool clubFocusMatches = (playerIsAttack ? (c.focus == 'A') : (c.focus == 'D'));

            if (best == -1) {
                best = i;
            } else {
                bool bestPlayerIsAttack = (players[0].atk >= players[0].def); // placeholder, won't be used
                (void)bestPlayerIsAttack;
                auto &b = clubs[best];

                bool bestClubFocusMatches = (playerIsAttack ? (b.focus == 'A') : (b.focus == 'D'));

                if (clubFocusMatches != bestClubFocusMatches) {
                    if (clubFocusMatches) best = i;
                } else {
                    if (c.money > b.money) best = i;
                    else if (c.money == b.money && c.order < b.order) best = i;
                }
            }
        }

        if (best == -1) {
            cout << p.name << " ta muito caro\n";
        } else {
            cout << p.name << " eh do " << clubs[best].name << "\n";
            clubs[best].money -= p.cost;
            clubs[best].players.push_back(&p - &players[0]);
        }
    }

    vector<Club> allClubs;
    allClubs.reserve(clubs.size() + 1);
    for (auto &c : clubs) allClubs.push_back(c);

    // Output final situation for each club in insertion order excluding Vasco
    // Need to match insertion order among non-Vasco clubs. We already stored order.
    sort(allClubs.begin(), allClubs.end(), [](const Club& a, const Club& b){
        return a.order < b.order;
    });

    for (int i = 0; i < (int)allClubs.size(); i++) {
        auto &c = allClubs[i];
        cout << "\nSituacao " << c.name << "\n";
        cout << "Dinheiro restante = " << c.money << "\n";
        cout << "Num de Jogadores = " << c.players.size() << "\n";
        for (int idx : c.players) {
            cout << players[idx].name << " " << players[idx].country << "\n";
        }
        if (i + 1 < (int)allClubs.size()) {
            cout << "\n";
        }
    }

    return 0;
}