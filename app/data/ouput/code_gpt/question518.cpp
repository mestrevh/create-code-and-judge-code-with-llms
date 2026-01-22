/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

int main() {
    int caso = 1, N, X;

    while (cin >> N >> X) {
        vector<int> forces(2 * (N * N - N));
        for (int i = 0; i < forces.size(); ++i) {
            cin >> forces[i];
        }

        vector<vector<int>> grid(N, vector<int>(N, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        grid[X / N][X % N] = 0;
        pq.emplace(0, X / N, X % N);

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();

            if (x == 0 || x == N - 1 || y == 0 || y == N - 1) {
                cout << "caso " << caso << ": " << cost << '\n';
                break;
            }

            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    int wallIndex = (x * 2 * (N - 1) + y * 2) + (dir < 2 ? (dir * 2 + 1) : (dir * 2));
                    int newCost = cost + forces[wallIndex];
                    if (newCost < grid[nx][ny]) {
                        grid[nx][ny] = newCost;
                        pq.emplace(newCost, nx, ny);
                    }
                }
            }
        }
        caso++;
        cin.ignore();
    }
    return 0;
}
