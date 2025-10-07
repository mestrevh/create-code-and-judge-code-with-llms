/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

const long long INF = 1e18;

struct State {
    long long time;
    int r, c, t_mod;

    bool operator>(const State& other) const {
        return time > other.time;
    }
};

void solve(int case_num) {
    int M, N;
    std::cin >> M >> N;

    if (M <= 0 || N <= 0) {
        int Q_dummy, P_dummy;
        std::cin >> Q_dummy >> P_dummy;
        for (int q = 0; q < Q_dummy; ++q) {
            int r1, c1, r2, c2;
            std::cin >> r1 >> c1 >> r2 >> c2;
        }
        if (M == 1 && N == 1) {
             std::cout << case_num << ": " << 0 << "\n";
        } else {
             // Ill-defined case, but based on constraints, this branch shouldn't be hit with valid logic.
        }
        return;
    }

    std::vector<std::vector<std::vector<std::pair<int, int>>>> adj(M, std::vector<std::vector<std::pair<int, int>>>(N));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::string s;
            std::cin >> s;
            for (char dir : s) {
                if (dir == 'N' && i > 0) adj[i][j].push_back({i - 1, j});
                if (dir == 'E' && j < N - 1) adj[i][j].push_back({i, j + 1});
                if (dir == 'S' && i < M - 1) adj[i][j].push_back({i + 1, j});
                if (dir == 'W' && j > 0) adj[i][j].push_back({i, j - 1});
            }
        }
    }

    int Q, P;
    std::cin >> Q >> P;

    std::vector<std::vector<std::vector<std::pair<int, int>>>> portals(M, std::vector<std::vector<std::pair<int, int>>>(N));
    for (int q = 0; q < Q; ++q) {
        int r1, c1, r2, c2;
        std::cin >> r1 >> c1 >> r2 >> c2;
        portals[r1][c1].push_back({r2, c2});
    }

    std::vector<std::vector<std::vector<long long>>> dist(M, std::vector<std::vector<long long>>(N, std::vector<long long>(P, INF)));
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

    if (M > 0 && N > 0) {
        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});
    }

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        long long d = current.time;
        int r = current.r;
        int c = current.c;
        int t_mod = current.t_mod;

        if (d > dist[r][c][t_mod]) {
            continue;
        }

        long long next_d_1s = d + 1;
        int next_t_mod_1s = (t_mod + 1) % P;
        
        if (next_d_1s < dist[r][c][next_t_mod_1s]) {
            dist[r][c][next_t_mod_1s] = next_d_1s;
            pq.push({next_d_1s, r, c, next_t_mod_1s});
        }
        
        for (const auto& neighbor : adj[r][c]) {
            int nr = neighbor.first;
            int nc = neighbor.second;
            if (next_d_1s < dist[nr][nc][next_t_mod_1s]) {
                dist[nr][nc][next_t_mod_1s] = next_d_1s;
                pq.push({next_d_1s, nr, nc, next_t_mod_1s});
            }
        }
        
        for (const auto& dest : portals[r][c]) {
            long long wait = (P - t_mod) % P;
            long long next_d_portal = d + wait + 1;
            int dest_r = dest.first;
            int dest_c = dest.second;
            if (next_d_portal < dist[dest_r][dest_c][1]) {
                dist[dest_r][dest_c][1] = next_d_portal;
                pq.push({next_d_portal, dest_r, dest_c, 1});
            }
        }
    }

    long long min_time = INF;
    if (M > 0 && N > 0) {
        for (int i = 0; i < P; ++i) {
            min_time = std::min(min_time, dist[M - 1][N - 1][i]);
        }
    } else if (M == 1 && N == 1) {
        min_time = 0;
    }
    
    std::cout << case_num << ": " << min_time << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L;
    std::cin >> L;
    for (int i = 0; i < L; ++i) {
        solve(i);
    }
    return 0;
}
