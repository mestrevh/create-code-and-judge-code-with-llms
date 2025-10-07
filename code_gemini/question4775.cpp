/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

struct Player {
    std::string name;
    int total_score = 0;
    int max_round_score = 0;
    bool is_eliminated = false;
    std::vector<std::string> correct_words;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 1) {
        std::cout << "Jogar com uma pessoa só nem tem graça...\n";
        return 0;
    }

    std::vector<Player> players(n);
    double total_bet = 0.0;
    bool has_azeik = false;
    bool has_odnanref = false;

    for (int i = 0; i < n; ++i) {
        double bet;
        std::cin >> players[i].name >> bet;
        total_bet += bet;
        if (players[i].name == "Azeik") {
            has_azeik = true;
        }
        if (players[i].name == "Odnanref") {
            has_odnanref = true;
        }
    }

    std::cout << "Hoje, quem vai jogar Azeik palavras é ";
    for (int i = 0; i < n; ++i) {
        std::cout << players[i].name;
        if (i == n - 1) {
            std::cout << ".\n";
        } else {
            std::cout << ", ";
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Tem muito dinheiro em jogo, quem vai levar a bolada de " << total_bet << " reais?\n";

    if (has_azeik) {
        std::cout << "Azeik todo mundo sabe que você vai ganhar, não precisa jogar, tome o dinheiro e vá jogar no tigrinho.\n";
        return 0;
    }

    if (has_odnanref) {
        std::cout << "Odnanref está aqui nem vale a pena jogar, esse cara atrapalha tudo!\n";
        return 0;
    }

    int num_rounds;
    std::cin >> num_rounds;

    int active_players = n;

    for (int r = 0; r < num_rounds; ++r) {
        if (active_players <= 1) {
            break;
        }

        std::string ref_word;
        std::cin >> ref_word;

        std::vector<int> to_be_eliminated;

        for (int i = 0; i < n; ++i) {
            if (!players[i].is_eliminated) {
                std::string chosen_word;
                std::cin >> chosen_word;

                if (chosen_word[0] == ref_word[0]) {
                    int round_score = chosen_word.length();
                    if (chosen_word == ref_word) {
                        round_score *= 2;
                        players[i].correct_words.push_back(ref_word);
                    }
                    players[i].total_score += round_score;
                    players[i].max_round_score = std::max(players[i].max_round_score, round_score);
                } else {
                    to_be_eliminated.push_back(i);
                }
            }
        }

        for (int index : to_be_eliminated) {
            players[index].is_eliminated = true;
            active_players--;
            std::cout << players[index].name << " foi eliminado e vai sair daqui sem um centavo.\n";
        }
    }

    Player* winner = nullptr;
    int max_score = -1;
    std::vector<Player*> potential_winners;

    for (int i = 0; i < n; ++i) {
        if (!players[i].is_eliminated) {
            if (players[i].total_score > max_score) {
                max_score = players[i].total_score;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!players[i].is_eliminated && players[i].total_score == max_score) {
            potential_winners.push_back(&players[i]);
        }
    }

    if (!potential_winners.empty()) {
        winner = potential_winners[0];
        for (size_t i = 1; i < potential_winners.size(); ++i) {
            if (potential_winners[i]->name < winner->name) {
                winner = potential_winners[i];
            }
        }
    
        bool tie_breaker_used = potential_winners.size() > 1;

        std::cout << "Temos um vencedor...\n";
        std::cout << winner->name << " venceu e levou a bolada de " << total_bet << " reais para casa!\n";
        std::cout << "E não para por aí, " << winner->name << " fez uma pontuação histórica de " << winner->total_score 
                  << " pontos, conseguindo um total de " << winner->max_round_score << " pontos numa só rodada!\n";

        if (!winner->correct_words.empty()) {
            std::cout << "Impressionante, " << winner->name << " ainda conseguiu acertar essas palavras de referência: ";
            for (size_t i = 0; i < winner->correct_words.size(); ++i) {
                std::cout << winner->correct_words[i];
                if (i == winner->correct_words.size() - 1) {
                    std::cout << "!\n";
                } else {
                    std::cout << ", ";
                }
            }
        }

        if (tie_breaker_used) {
            std::cout << "E mesmo com tudo isso, foi apertado. Agradeça a seus pais, que foram eles que fizeram você ganhar esse dinheiro.\n";
        }
    }
    
    return 0;
}
