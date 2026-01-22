/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int test_case_num = 1;
    while (std::cin >> n && n != 0) {
        std::map<std::string, int> name_to_id;
        std::vector<std::string> id_to_name(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> id_to_name[i];
            name_to_id[id_to_name[i]] = i;
        }

        std::vector<std::vector<int>> adj(n);
        std::vector<int> in_degree(n, 0);

        for (int i = 0; i < n; ++i) {
            std::string u_name;
            int m;
            std::cin >> u_name >> m;
            int u_id = name_to_id[u_name];
            
            for (int j = 0; j < m; ++j) {
                std::string v_name;
                std::cin >> v_name;
                int v_id = name_to_id[v_name];
                adj[v_id].push_back(u_id);
                in_degree[u_id]++;
            }
        }

        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        std::vector<int> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            for (int v : adj[u]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }

        std::cout << "Teste " << test_case_num++ << std::endl;
        if (result.size() == n) {
            for (size_t i = 0; i < result.size(); ++i) {
                std::cout << id_to_name[result[i]] << (i == result.size() - 1 ? "" : " ");
            }
            std::cout << std::endl;
        } else {
            std::cout << "impossivel" << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
