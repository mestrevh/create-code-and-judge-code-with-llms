/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    double bet;
    int score = 0;
    int max_round_score = 0;
    vector<string> correct_words;
    bool eliminated = false;
};

int main() {
    int num_players;
    cin >> num_players;
    cin.ignore(); 

    if (num_players == 1) {
        cout << "Jogar com uma pessoa só nem tem graça...\n";
        return 0;
    }

    vector<Player> players(num_players);
    double total_bet = 0;
    for (int i = 0; i < num_players; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        ss >> players[i].name >> players[i].bet;
        total_bet += players[i].bet;
    }

    cout << "Hoje, quem vai jogar Azeik palavras é ";
    for (int i = 0; i < num_players; ++i) {
        cout << players[i].name;
        if (i < num_players - 1) {
            cout << ", ";
        }
    }
    cout << ".\n";

    cout << "Tem muito dinheiro em jogo, quem vai levar a bolada de " << fixed << setprecision(2) << total_bet << " reais?\n";

    for (int i = 0; i < num_players; ++i) {
        if (players[i].name == "Azeik") {
            cout << "Azeik todo mundo sabe que você vai ganhar, não precisa jogar, tome o dinheiro e vá jogar no tigrinho.\n";
            return 0;
        }
        if (players[i].name == "Odnanref") {
            cout << "Odnanref está aqui nem vale a pena jogar, esse cara atrapalha tudo!\n";
            return 0;
        }
    }

    int num_rounds;
    cin >> num_rounds;
    cin.ignore();

    for (int round = 0; round < num_rounds; ++round) {
        string reference_word;
        cin >> reference_word;
        
        int remaining_players = 0;
        for (int i = 0; i < num_players; ++i) {
            if (!players[i].eliminated) {
                remaining_players++;
            }
        }
        if(remaining_players == 1) break;

        for (int i = 0; i < num_players; ++i) {
            if (!players[i].eliminated) {
                string player_word;
                cin >> player_word;

                if (player_word[0] == reference_word[0]) {
                    int round_score = player_word.length();
                    if (player_word == reference_word) {
                        round_score *= 2;
                        players[i].correct_words.push_back(reference_word);
                    }
                    players[i].score += round_score;
                    players[i].max_round_score = max(players[i].max_round_score, round_score);
                } else {
                    cout << players[i].name << " foi eliminado e vai sair daqui sem um centavo.\n";
                    players[i].eliminated = true;
                }
            }
        }
    }

    Player winner;
    int winner_count = 0;
    for(auto& p : players){
        if(!p.eliminated){
            if(winner_count == 0 || p.score > winner.score || (p.score == winner.score && p.name < winner.name)){
                winner = p;
            }
            winner_count++;
        }
    }
    

    cout << "Temos um vencedor...\n";
    cout << winner.name << " venceu e levou a bolada de " << fixed << setprecision(2) << total_bet << " reais para casa!\n";
    cout << "E não para por aí, " << winner.name << " fez uma pontuação histórica de " << winner.score << " pontos, conseguindo um total de " << winner.max_round_score << " pontos numa só rodada!\n";

    if (!winner.correct_words.empty()) {
        cout << "Impressionante, " << winner.name << " ainda conseguiu acertar essas palavras de referência: ";
        for (size_t i = 0; i < winner.correct_words.size(); ++i) {
            cout << winner.correct_words[i];
            if (i < winner.correct_words.size() - 1) {
                cout << ", ";
            }
        }
        cout << "!\n";
    }

    if(winner_count > 1 && winner.score == players[0].score){
        
        int same_score = 0;
         for(auto& p : players){
             if(p.score == winner.score){
                 same_score++;
             }
         }
         if(same_score > 1)
            cout << "E mesmo com tudo isso, foi apertado. Agradeça a seus pais, que foram eles que fizeram você ganhar esse dinheiro.\n";

    }


    return 0;
}
