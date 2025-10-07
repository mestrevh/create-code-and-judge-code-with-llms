/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const char direction[4] = {'S', 'E', 'N', 'W'};

int Dijkstra(int M, int N, const vector<string>& grid, const vector<tuple<int, int, int, int>>& portals, int P) {
    vector<vector<int>> dist(M, vector<int>(N, INF));
    dist[0][0] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.emplace(0, 0, 0);
    
    while (!pq.empty()) {
        auto [time, x, y] = pq.top();
        pq.pop();

        if (time > dist[x][y]) continue;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && grid[x][y] == direction[d]) {
                if (dist[nx][ny] > time + 1) {
                    dist[nx][ny] = time + 1;
                    pq.emplace(dist[nx][ny], nx, ny);
                }
            }
        }

        for (const auto& [start_x, start_y, end_x, end_y] : portals) {
            if (x == start_x && y == start_y) {
                int wait_time = (time % P == 0) ? 0 : P - (time % P);
                int arrive_time = time + 1 + wait_time;
                if (dist[end_x][end_y] > arrive_time) {
                    dist[end_x][end_y] = arrive_time;
                    pq.emplace(arrive_time, end_x, end_y);
                }
            }
        }
    }
    
    return dist[M-1][N-1];
}

int main() {
    int L;
    cin >> L;
    for (int k = 0; k < L; ++k) {
        int M, N;
        cin >> M >> N;
        vector<string> grid(M);
        for (int i = 0; i < M; ++i)
            cin >> grid[i];

        int Q, P;
        cin >> Q >> P;
        vector<tuple<int, int, int, int>> portals(Q);
        for (int i = 0; i < Q; ++i) {
            int I1, J1, I2, J2;
            cin >> I1 >> J1 >> I2 >> J2;
            portals[i] = {I1, J1, I2, J2};
        }

        int result = Dijkstra(M, N, grid, portals, P);
        cout << k << ": " << result << endl;
        
        if (k < L - 1) cout << endl;
    }
    return 0;
}
