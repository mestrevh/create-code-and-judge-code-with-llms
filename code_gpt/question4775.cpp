/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Player {
    string name;
    float bet;
    int score;
    vector<string> correctWords;
};

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "Jogar com uma pessoa só nem tem graça...\n";
        return 0;
    }

    vector<Player> players(n);
    float totalBet = 0.0;
    
    for (int i = 0; i < n; ++i) {
        cin >> players[i].name >> players[i].bet;
        players[i].score = 0;
        totalBet += players[i].bet;
    }

    cout << fixed << setprecision(2);
    cout << "Hoje, quem vai jogar Azeik palavras é ";
    for (int i = 0; i < n; ++i) {
        cout << players[i].name;
        if (i < n - 1) cout << ", ";
    }
    cout << ".\n";
    cout << "Tem muito dinheiro em jogo, quem vai levar a bolada de " << totalBet << " reais?\n";

    string wordReference, chosenWord;
    int rounds;
    cin >> rounds;

    bool Azeik = false, Odnanref = false;
    
    for (int r = 0; r < rounds; ++r) {
        cin >> wordReference;
        vector<bool> eliminated(n, false);
        int remaining = n;
        
        for (int i = 0; i < n; ++i) {
            if (eliminated[i]) continue;
            cin >> chosenWord;
            if (chosenWord == "Azeik") Azeik = true;
            else if (chosenWord == "Odnanref") Odnanref = true;

            if (chosenWord[0] == wordReference[0]) {
                players[i].score += chosenWord.length();
                if (chosenWord == wordReference) {
                    players[i].score += chosenWord.length();
                    players[i].correctWords.push_back(wordReference);
                }
            } else {
                eliminated[i] = true;
                cout << players[i].name << " foi eliminado e vai sair daqui sem um centavo.\n";
                remaining--;
            }
        }

        n = remaining;
        if (n <= 1) break;
    }

    if (Azeik) {
        cout << "Azeik todo mundo sabe que você vai ganhar, não precisa jogar, tome o dinheiro e vá jogar no tigrinho.\n";
        return 0;
    } else if (Odnanref) {
        cout << "Odnanref está aqui nem vale a pena jogar, esse cara atrapalha tudo!\n";
        return 0;
    }

    Player winner;
    int maxScore = -1;

    for (const auto &player : players) {
        if (player.score > maxScore || (player.score == maxScore && player.name < winner.name)) {
            winner = player;
            maxScore = player.score;
        }
    }

    cout << "Temos um vencedor...\n";
    cout << winner.name << " venceu e levou a bolada de " << totalBet << " reais para casa!\n";
    cout << "E não para por aí, " << winner.name << " fez uma pontuação histórica de " << winner.score << " pontos, conseguindo um total de " 
         << (maxScore / 2) << " pontos numa só rodada!\n";

    if (!winner.correctWords.empty()) {
        cout << "Impressionante, " << winner.name << " ainda conseguiu acertar essas palavras de referência: ";
        for (size_t i = 0; i < winner.correctWords.size(); i++) {
            cout << winner.correctWords[i];
            if (i < winner.correctWords.size() - 1) cout << ", ";
        }
        cout << "!\n";
    }
    return 0;
}
