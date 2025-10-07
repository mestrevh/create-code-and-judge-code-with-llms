/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int case_num = 0;
    int N;
    bool first_case = true;

    while (std::cin >> N) {
        if (!first_case) {
            std::cout << std::endl;
        }
        first_case = false;

        int S;
        std::cin >> S;

        std::vector<std::vector<int>> adj(N);
        for (int i = 0; i < N; ++i) {
            int k;
            std::cin >> k;
            adj[i].resize(k);
            for (int j = 0; j < k; ++j) {
                std::cin >> adj[i][j];
            }
        }

        std::cout << "caso " << case_num++ << ":";

        std::queue<int> q;
        std::vector<int> times(N, -1);
        
        q.push(S);
        times[S] = 0;
        
        int max_time = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (times[v] == -1) {
                    times[v] = times[u] + 1;
                    max_time = std::max(max_time, times[v]);
                    q.push(v);
                }
            }
        }
        
        std::vector<int> new_infections_per_second(max_time + 1, 0);
        for (int t : times) {
            if (t != -1) {
                new_infections_per_second[t]++;
            }
        }
        
        int cumulative = 0;
        for (int t = 0; t <= max_time; ++t) {
            cumulative += new_infections_per_second[t];
            std::cout << " " << cumulative;
        }
        std::cout << std::endl;
    }

    return 0;
}
