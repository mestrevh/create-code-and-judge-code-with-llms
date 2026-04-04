/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
    int id;
    long long score;
};

bool comparePlayers(const Player& a, const Player& b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }
    return a.id > b.id;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<int>> mat(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> mat[i][j];
        }
    }

    vector<bool> eliminated(N + 1, false);
    for (int x = 1; x <= N; ++x) {
        if (x == 1) continue;
        int i = x - 1; // Championship X (0-indexed)
        int j = x - 1; // Player X (0-indexed column)
        if (i < M && j < N) {
            if (mat[i][j] == x) {
                eliminated[x] = true;
            }
        }
    }

    vector<Player> results;
    for (int j = 0; j < N; ++j) {
        int player_id = j + 1;
        if (eliminated[player_id]) continue;

        long long total_score = 0;
        for (int i = 0; i < M; ++i) {
            int rank = mat[i][j];
            long long points = (N - rank + 1);
            total_score += points * (i + 1);
        }
        results.push_back({player_id, total_score});
    }

    sort(results.begin(), results.end(), comparePlayers);

    if (results.size() >= 1) {
        cout << "O primeiro lugar foi: " << results[0].id << "\n";
    }
    if (results.size() >= 2) {
        cout << "O segundo lugar foi: " << results[1].id << "\n";
    }
    if (results.size() >= 3) {
        cout << "O terceiro lugar foi: " << results[2].id << "\n";
    }

    return 0;
}