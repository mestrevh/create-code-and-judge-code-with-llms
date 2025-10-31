/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <cstdint>

uint32_t calculate_feedback(uint32_t state, const std::vector<int>& taps) {
    uint32_t feedback = 0;
    for (int tap_pos : taps) {
        if (tap_pos < 32) {
            feedback ^= (state >> tap_pos) & 1;
        }
    }
    return feedback;
}

std::vector<uint32_t> get_predecessors(uint32_t current_state, int N, const std::vector<int>& taps) {
    std::vector<uint32_t> predecessors;
    uint32_t required_feedback = current_state & 1;

    uint32_t p0 = current_state >> 1;
    if (calculate_feedback(p0, taps) == required_feedback) {
        predecessors.push_back(p0);
    }

    if (N > 0) {
        uint32_t msb_mask = (N == 32) ? (1u << 31) : (1u << (N - 1));
        uint32_t p1 = (current_state >> 1) | msb_mask;
        if (p0 != p1 && calculate_feedback(p1, taps) == required_feedback) {
            predecessors.push_back(p1);
        }
    }
    return predecessors;
}

void solve() {
    int N, T;
    while (std::cin >> N >> T && (N != 0 || T != 0)) {
        std::vector<int> taps(T);
        for (int i = 0; i < T; ++i) {
            std::cin >> taps[i];
        }
        std::string i_str, f_str;
        std::cin >> i_str >> f_str;

        uint32_t initial_state, final_state;
        std::stringstream ss;
        ss << std::hex << i_str;
        ss >> initial_state;
        ss.clear();
        ss << std::hex << f_str;
        ss >> final_state;

        if (initial_state == final_state) {
            std::cout << 0 << "\n";
            continue;
        }

        uint32_t mask = (N == 32) ? 0xFFFFFFFF : (1u << N) - 1;

        std::queue<uint32_t> q_fwd, q_bwd;
        std::unordered_map<uint32_t, int> dist_fwd, dist_bwd;

        q_fwd.push(initial_state);
        dist_fwd[initial_state] = 0;

        q_bwd.push(final_state);
        dist_bwd[final_state] = 0;
        
        bool found = false;

        while (!q_fwd.empty() && !q_bwd.empty()) {
            
            if (q_fwd.size() <= q_bwd.size()) {
                uint32_t u = q_fwd.front();
                q_fwd.pop();
                
                uint32_t feedback = calculate_feedback(u, taps);
                uint32_t v = ((u << 1) | feedback) & mask;

                if (dist_bwd.count(v)) {
                    std::cout << dist_fwd[u] + 1 + dist_bwd[v] << "\n";
                    found = true;
                    break;
                }

                if (!dist_fwd.count(v)) {
                    dist_fwd[v] = dist_fwd[u] + 1;
                    q_fwd.push(v);
                }
            } else {
                uint32_t u = q_bwd.front();
                q_bwd.pop();

                std::vector<uint32_t> predecessors = get_predecessors(u, N, taps);

                for (uint32_t p : predecessors) {
                    if (dist_fwd.count(p)) {
                        std::cout << dist_bwd[u] + 1 + dist_fwd[p] << "\n";
                        found = true;
                        break;
                    }
                    if (!dist_bwd.count(p)) {
                        dist_bwd[p] = dist_bwd[u] + 1;
                        q_bwd.push(p);
                    }
                }
                if (found) break;
            }
        }

        if (!found) {
            std::cout << "*" << "\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
