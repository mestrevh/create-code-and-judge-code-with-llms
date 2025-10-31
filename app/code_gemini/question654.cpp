/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <limits>
#include <functional>

struct Word {
    int lang1_id;
    int lang2_id;
    char first_char;
    int length;
};

using State = std::pair<int, int>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M;
    while (std::cin >> M && M != 0) {
        std::string origin_lang_str, dest_lang_str;
        std::cin >> origin_lang_str >> dest_lang_str;

        std::map<std::string, int> lang_to_id;
        int next_lang_id = 0;
        
        auto get_lang_id = [&](const std::string& lang_str) -> int {
            if (lang_to_id.find(lang_str) == lang_to_id.end()) {
                lang_to_id[lang_str] = next_lang_id++;
            }
            return lang_to_id[lang_str];
        };

        get_lang_id(origin_lang_str);
        get_lang_id(dest_lang_str);
        int origin_id = lang_to_id[origin_lang_str];
        int dest_id = lang_to_id[dest_lang_str];

        std::vector<Word> words(M);
        for (int i = 0; i < M; ++i) {
            std::string l1_str, l2_str, w_str;
            std::cin >> l1_str >> l2_str >> w_str;
            words[i] = {get_lang_id(l1_str), get_lang_id(l2_str), w_str[0], (int)w_str.length()};
        }

        std::vector<std::vector<int>> adj(M);
        if (M > 0) {
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < M; ++j) {
                    if (i == j) continue;
                    
                    bool share_lang = (words[i].lang1_id == words[j].lang1_id ||
                                       words[i].lang1_id == words[j].lang2_id ||
                                       words[i].lang2_id == words[j].lang1_id ||
                                       words[i].lang2_id == words[j].lang2_id);
                               
                    if (share_lang && words[i].first_char != words[j].first_char) {
                        adj[i].push_back(j);
                    }
                }
            }
        }
        
        const int INF = std::numeric_limits<int>::max();
        std::vector<int> dist(M, INF);
        std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

        for (int i = 0; i < M; ++i) {
            if (words[i].lang1_id == origin_id || words[i].lang2_id == origin_id) {
                dist[i] = words[i].length;
                pq.push({dist[i], i});
            }
        }

        while (!pq.empty()) {
            auto [current_cost, u_idx] = pq.top();
            pq.pop();

            if (current_cost > dist[u_idx]) {
                continue;
            }

            for (int v_idx : adj[u_idx]) {
                int new_cost = current_cost + words[v_idx].length;
                if (new_cost < dist[v_idx]) {
                    dist[v_idx] = new_cost;
                    pq.push({new_cost, v_idx});
                }
            }
        }

        int min_total_length = INF;
        for (int i = 0; i < M; ++i) {
            if (words[i].lang1_id == dest_id || words[i].lang2_id == dest_id) {
                if (dist[i] < min_total_length) {
                    min_total_length = dist[i];
                }
            }
        }

        if (min_total_length == INF) {
            std::cout << "impossivel\n";
        } else {
            std::cout << min_total_length << "\n";
        }
    }

    return 0;
}
