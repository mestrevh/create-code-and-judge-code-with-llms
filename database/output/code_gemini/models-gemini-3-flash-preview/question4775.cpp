/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    double bet;
    int total_score = 0;
    int max_single_round = 0;
    bool active = true;
    vector<string> matched_words;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n == 1) {
        string name;
        double bet;
        if (cin >> name >> bet) {
            cout << "Jogar com uma pessoa só nem tem graça..." << endl;
        }
        return 0;
    }

    vector<Player> players(n);
    double total_bet = 0;
    bool has_azeik = false;
    bool has_odnanref = false;

    for (int i = 0; i < n; ++i) {
        cin >> players[i].name >> players[i].bet;
        total_bet += players[i].bet;
        if (players[i].name == "Azeik") has_azeik = true;
        if (players[i].name == "Odnanref") has_odnanref = true;
    }

    cout << "Hoje, quem vai jogar Azeik palavras é ";
    for (int i = 0; i < n; ++i) {
        cout << players[i].name << (i == n - 1 ? ".\n" : ", ");
    }
    cout << "Tem muito dinheiro em jogo, quem vai levar a bolada de " << fixed << setprecision(2) << total_bet << " reais?" << endl;

    if (has_azeik) {
        cout << "Azeik todo mundo sabe que você vai ganhar, não precisa jogar, tome o dinheiro e vá jogar no tigrinho." << endl;
        return 0;
    }
    if (has_odnanref) {
        cout << "Odnanref está aqui nem vale a pena jogar, esse cara atrapalha tudo!" << endl;
        return 0;
    }

    int x;
    if (!(cin >> x)) return 0;

    int active_count = n;
    for (int r = 0; r < x; ++r) {
        if (active_count <= 1) break;
        string w_ref;
        if (!(cin >> w_ref)) break;
        for (int i = 0; i < n; ++i) {
            if (!players[i].active) continue;
            if (active_count <= 1) break;
            string w_p;
            if (!(cin >> w_p)) break;
            if (w_p[0] == w_ref[0]) {
                int pts = w_p.length();
                if (w_p == w_ref) {
                    pts *= 2;
                    players[i].matched_words.push_back(w_p);
                }
                players[i].total_score += pts;
                if (pts > players[i].max_single_round) {
                    players[i].max_single_round = pts;
                }
            } else {
                players[i].active = false;
                active_count--;
                cout << players[i].name << " foi eliminado e vai sair daqui sem um centavo." << endl;
            }
        }
    }

    int max_score = -1;
    for (int i = 0; i < n; i++) {
        if (players[i].active) {
            if (players[i].total_score > max_score) {
                max_score = players[i].total_score;
            }
        }
    }

    vector<Player*> candidates;
    for (int i = 0; i < n; i++) {
        if (players[i].active && players[i].total_score == max_score) {
            candidates.push_back(&players[i]);
        }
    }

    if (candidates.empty()) return 0;

    sort(candidates.begin(), candidates.end(), [](Player* a, Player* b) {
        return a->name < b->name;
    });

    Player* winner = candidates[0];
    bool tie_msg = (candidates.size() > 1);

    cout << "Temos um vencedor..." << endl;
    cout << winner->name << " venceu e levou a bolada de " << fixed << setprecision(2) << total_bet << " reais para casa!" << endl;
    cout << "E não para por aí, " << winner->name << " fez uma pontuação histórica de " << winner->total_score << " pontos, conseguindo um total de " << winner->max_single_round << " pontos numa só rodada!" << endl;

    if (!winner->matched_words.empty()) {
        cout << "Impressionante, " << winner->name << " ainda conseguiu acertar essas palavras de referência: ";
        for (size_t i = 0; i < winner->matched_words.size(); ++i) {
            cout << winner->matched_words[i] << (i == (int)winner->matched_words.size() - 1 ? "!\n" : ", ");
        }
    }

    if (tie_msg) {
        cout << "E mesmo com tudo isso, foi apertado. Agradeça a seus pais, que foram eles que fizeram você ganhar esse dinheiro." << endl;
    }

    return 0;
}