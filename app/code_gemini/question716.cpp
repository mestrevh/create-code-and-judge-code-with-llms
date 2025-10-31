/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int case_num = 0;
    int N, M, K, P;
    long long A;

    while (std::cin >> N >> M >> K >> P >> A) {
        if (case_num > 0) {
            std::cout << "\n";
        }

        std::cout << "caso " << case_num << ":";

        std::vector<int> balls(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> balls[i];
        }

        std::sort(balls.begin(), balls.end());

        std::unordered_map<int, int> rank_map;
        rank_map.reserve(N);
        for (int i = 0; i < N; ++i) {
            rank_map[balls[i]] = i;
        }

        for (int j = 0; j < P; ++j) {
            long long score = 0;
            for (int k = 0; k < K; ++k) {
                int drawn_ball;
                std::cin >> drawn_ball;
                score += rank_map.at(drawn_ball);
            }
            if (score == A) {
                std::cout << " " << j;
            }
        }
        std::cout << "\n";

        case_num++;
    }

    return 0;
}
