/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>

const int MAX_VARS_BASE = 100 + 500;
const int MAX_CLAUSE_AUX = 4;
const int MAX_NODES = (MAX_VARS_BASE + 500 * 4 * MAX_CLAUSE_AUX) * 2;

std::vector<int> adj[MAX_NODES];
std::vector<int> rev_adj[MAX_NODES];
bool visited[MAX_NODES];
int component[MAX_NODES];
std::vector<int> order;
int B, M;
int num_vars;

struct Edge { int u, v; };
std::vector<Edge> temp_edges;

void add_edge(int u, int v, bool is_temp) {
    adj[u].push_back(v);
    rev_adj[v].push_back(u);
    if (is_temp) {
        temp_edges.push_back({u, v});
    }
}

void remove_temp_edges() {
    for(const auto& edge : temp_edges) {
        adj[edge.u].pop_back();
        rev_adj[edge.v].pop_back();
    }
    temp_edges.clear();
}

void add_implication(int u, int v, bool is_temp = false) {
    add_edge(u, v, is_temp);
    add_edge(v ^ 1, u ^ 1, is_temp);
}

void add_clause(int u, int v, bool is_temp = false) {
    add_implication(u ^ 1, v, is_temp);
}

void add_or_clause(const std::vector<int>& literals, bool is_temp = false) {
    if (literals.empty()) {
        if(is_temp) {
            int false_node = 2 * (num_vars++);
            add_implication(false_node, false_node^1, true);
        } else {
             int false_node = 2 * (num_vars++);
             add_implication(false_node, false_node^1, false);
        }
        return;
    }
    if (literals.size() == 1) {
        add_clause(literals[0], literals[0], is_temp);
        return;
    }
    if (literals.size() == 2) {
        add_clause(literals[0], literals[1], is_temp);
        return;
    }

    int aux = 2 * (num_vars++);
    add_clause(literals[0], aux, is_temp);
    
    std::vector<int> rest;
    rest.push_back(aux ^ 1);
    for (size_t i = 1; i < literals.size(); ++i) {
        rest.push_back(literals[i]);
    }
    add_or_clause(rest, is_temp);
}

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs1(v);
    }
    order.push_back(u);
}

void dfs2(int u, int c) {
    component[u] = c;
    for (int v : rev_adj[u]) {
        if (component[v] == -1) dfs2(v, c);
    }
}

bool check_sat(int current_vars) {
    order.clear();
    for (int i = 0; i < 2 * current_vars; ++i) {
        visited[i] = false;
        component[i] = -1;
    }
    for (int i = 0; i < 2 * current_vars; ++i) {
        if (!visited[i]) dfs1(i);
    }
    int c = 0;
    std::reverse(order.begin(), order.end());
    for (int u : order) {
        if (component[u] == -1) dfs2(u, c++);
    }
    for (int i = 0; i < current_vars; ++i) {
        if (component[2 * i] == component[2 * i + 1] && component[2 * i] != -1) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int case_num = 1;
    while (std::cin >> B >> M && (B != 0 || M != 0)) {
        for (int i = 0; i < MAX_NODES; ++i) {
            adj[i].clear();
            rev_adj[i].clear();
        }
        num_vars = B;

        for (int i = 0; i < M; ++i) {
            int k; std::cin >> k;
            std::vector<int> l(k);
            for (int j = 0; j < k; ++j) {
                int bill_idx; char vote;
                std::cin >> bill_idx >> vote;
                bill_idx--;
                l[j] = (vote == 's') ? (2 * bill_idx) : (2 * bill_idx + 1);
            }

            if (k <= 2) {
                add_or_clause(l);
            } else if (k == 3) { // at most 1 wrong
                add_clause(l[0], l[1]);
                add_clause(l[0], l[2]);
                add_clause(l[1], l[2]);
            } else if (k == 4) { // at most 2 wrong
                add_or_clause({l[0], l[1], l[2]});
                add_or_clause({l[0], l[1], l[3]});
                add_or_clause({l[0], l[2], l[3]});
                add_or_clause({l[1], l[2], l[3]});
            }
        }
        
        int base_num_vars = num_vars;
        
        std::cout << "Caso " << case_num++ << ": ";
        if (!check_sat(base_num_vars)) {
            std::cout << "impossivel\n";
        } else {
            std::string result = "";
            for (int i = 0; i < B; ++i) {
                int current_num_vars = base_num_vars;
                add_clause(2 * i, 2 * i, true); // force S
                bool possible_S = check_sat(current_num_vars);
                remove_temp_edges();

                current_num_vars = base_num_vars;
                add_clause(2 * i + 1, 2 * i + 1, true); // force N
                bool possible_N = check_sat(current_num_vars);
                remove_temp_edges();
                
                if (possible_S && !possible_N) {
                    result += 'S';
                } else if (!possible_S && possible_N) {
                    result += 'N';
                } else {
                    result += '?';
                }
            }
             std::cout << result << "\n";
        }
    }
    return 0;
}
