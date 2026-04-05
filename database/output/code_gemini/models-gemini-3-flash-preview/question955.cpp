/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int INF = 1e9;

struct State {
    int r, c, d;
    bool operator>(const State& other) const {
        return d > other.d;
    }
};

struct Portal {
    int tr, tc;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L;
    if (!(cin >> L)) return 0;
    for (int k = 0; k < L; ++k) {
        int M, N;
        if (!(cin >> M >> N)) break;
        
        vector<string> grid_data(M * N);
        for (int i = 0; i < M * N; ++i) {
            cin >> grid_data[i];
        }

        int Q, P;
        cin >> Q >> P;
        vector<Portal> portals[100][100];
        for (int i = 0; i < Q; ++i) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            if (r1 >= 0 && r1 < M && c1 >= 0 && c1 < N) {
                portals[r1][c1].push_back({r2, c2});
            }
        }

        priority_queue<State, vector<State>, greater<State>> pq;
        vector<vector<int>> dist(M, vector<int>(N, INF));

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        int result = -1;
        while (!pq.empty()) {
            State curr = pq.top();
            pq.pop();

            if (curr.d > dist[curr.r][curr.c]) continue;
            if (curr.r == M - 1 && curr.c == N - 1) {
                result = curr.d;
                break;
            }

            // Normal moves: Neighboring cells
            const string& moves = grid_data[curr.r * N + curr.c];
            for (char m : moves) {
                int nr = curr.r, nc = curr.c;
                if (m == 'N') nr--;
                else if (m == 'E') nc++;
                else if (m == 'S') nr++;
                else if (m == 'W') nc--;

                if (nr >= 0 && nr < M && nc >= 0 && nc < N) {
                    if (dist[nr][nc] > curr.d + 1) {
                        dist[nr][nc] = curr.d + 1;
                        pq.push({nr, nc, dist[nr][nc]});
                    }
                }
            }

            // Magic Portals
            for (const auto& p : portals[curr.r][curr.c]) {
                // Portals open at t = 0, P, 2P, 3P...
                int wait_time = (curr.d % P == 0) ? 0 : (P - (curr.d % P));
                int arrival = curr.d + wait_time + 1;
                
                if (p.tr >= 0 && p.tr < M && p.tc >= 0 && p.tc < N) {
                    if (dist[p.tr][p.tc] > arrival) {
                        dist[p.tr][p.tc] = arrival;
                        pq.push({p.tr, p.tc, arrival});
                    }
                }
            }
        }
        cout << k << ": " << result << "\n";
    }

    return 0;
}