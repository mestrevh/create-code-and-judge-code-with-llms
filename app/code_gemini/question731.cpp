/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

void solve(int case_num) {
    int n;
    std::cin >> n;
    std::vector<int> x(n + 1);
    std::vector<int> in_degree(n + 1, 0);
    std::vector<std::vector<int>> rev_adj(n + 1);

    for (int i = 1; i <= n; ++i) {
        std::cin >> x[i];
        if (x[i] > 0) {
            in_degree[x[i]]++;
            rev_adj[x[i]].push_back(i);
        }
    }

    int no_alibi_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            no_alibi_count++;
        }
    }

    std::vector<bool> suspect(n + 1, false);
    std::vector<int> remaining_alibis(n + 1, 0);
    std::queue<int> q;
    int suspect_count = 0;

    for (int i = 1; i <= n; ++i) {
        bool has_non_self_alibi = false;
        for (int alibi : rev_adj[i]) {
            if (alibi != i) {
                remaining_alibis[i]++;
                has_non_self_alibi = true;
            }
        }
        if (!has_non_self_alibi) {
            if (!suspect[i]) {
                suspect[i] = true;
                suspect_count++;
                q.push(i);
            }
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int v = x[u];
        if (v > 0 && v != u) {
            if (!suspect[v]) {
                remaining_alibis[v]--;
                if (remaining_alibis[v] == 0) {
                    suspect[v] = true;
                    suspect_count++;
                    q.push(v);
                }
            }
        }
    }

    std::cout << "Caso #" << case_num << ": " << no_alibi_count << " " << suspect_count << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}
