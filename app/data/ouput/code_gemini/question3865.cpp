/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, tamX, tamY;
    std::cin >> N >> tamX >> tamY;

    std::vector<std::pair<int, int>> coords(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> coords[i].first >> coords[i].second;
    }

    std::vector<std::vector<int>> board(tamX, std::vector<int>(tamY));
    for (int i = 0; i < tamX; ++i) {
        for (int j = 0; j < tamY; ++j) {
            std::cin >> board[i][j];
        }
    }

    int max_overall_score = 0;

    for (const auto& coord : coords) {
        int x = coord.first;
        int y = coord.second;

        std::vector<int> scores(5, 0);

        for (int j = 0; j < tamY; ++j) {
            scores[board[x][j]]++;
        }

        for (int i = 0; i < tamX; ++i) {
            scores[board[i][y]]++;
        }

        scores[board[x][y]]--;

        int max_score_for_this_coord = *std::max_element(scores.begin() + 1, scores.end());
       
        max_overall_score = std::max(max_overall_score, max_score_for_this_coord);
    }

    std::cout << "A pontuacao da equipe vencedora sera " << max_overall_score << " ponto(s)!";

    return 0;
}
