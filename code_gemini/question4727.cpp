/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int K;
    std::cin >> K;

    std::map<int, std::string> score_to_name;
    std::map<std::string, int> name_to_score;

    for (int i = 0; i < K; ++i) {
        std::string command;
        std::cin >> command;

        if (command == "ADD") {
            std::string name;
            int score;
            std::cin >> name >> score;

            if (name_to_score.count(name)) {
                std::cout << name << " ja esta no sistema.\n";
            } else {
                name_to_score[name] = score;
                score_to_name[score] = name;
                std::cout << name << " inserido com sucesso!\n";
            }
        } else if (command == "PROX") {
            int score;
            std::cin >> score;

            auto it = score_to_name.find(score);
            std::string N = it->second;

            bool has_pred = (it != score_to_name.begin());
            auto next_it = std::next(it);
            bool has_succ = (next_it != score_to_name.end());

            if (!has_pred && !has_succ) {
                std::cout << "Apenas " << N << " existe no sistema...\n";
            } else if (!has_pred && has_succ) {
                std::string SUC = next_it->second;
                std::cout << N << " e o menor! e logo apos vem " << SUC << "\n";
            } else if (has_pred && !has_succ) {
                auto pred_it = std::prev(it);
                std::string PRE = pred_it->second;
                std::cout << N << " e o maior! e logo atras vem " << PRE << "\n";
            } else {
                auto pred_it = std::prev(it);
                std::string PRE = pred_it->second;
                std::string SUC = next_it->second;
                std::cout << N << " vem apos " << PRE << " e antes de " << SUC << "\n";
            }
        }
    }

    return 0;
}
