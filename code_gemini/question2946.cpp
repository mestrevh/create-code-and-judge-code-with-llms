/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> positions(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> positions[i][j];
        }
    }

    std::vector<bool> eliminated(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int champ_num = i + 1;
        for (int j = 0; j < n; ++j) {
            int player_id = j + 1;
            int pos = positions[i][j];
            if (player_id > 1 && player_id == pos && player_id == champ_num) {
                eliminated[player_id] = true;
            }
        }
    }

    std::vector<long long> scores(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int champ_num = i + 1;
        for (int j = 0; j < n; ++j) {
            int player_id = j + 1;
            int pos = positions[i][j];
            long long points = (long long)(n - pos + 1) * champ_num;
            scores[player_id] += points;
        }
    }

    std::vector<std::pair<long long, int>> ranking;
    for (int i = 1; i <= n; ++i) {
        if (!eliminated[i]) {
            ranking.push_back({scores[i], i});
        }
    }

    std::sort(ranking.begin(), ranking.end(), [](const std::pair<long long, int>& a, const std::pair<long long, int>& b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second > b.second;
    });

    std::cout << "O primeiro lugar foi: " << ranking[0].second << "\n";
    std::cout << "O segundo lugar foi: " << ranking[1].second << "\n";
    std::cout << "O terceiro lugar foi: " << ranking[2].second << "\n";

    return 0;
}
