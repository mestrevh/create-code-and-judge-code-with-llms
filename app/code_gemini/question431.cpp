/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n1, n2;
    while (std::cin >> n1 >> n2) {
        std::unordered_set<std::string> set_a;
        set_a.reserve(n1);
        for (int i = 0; i < n1; ++i) {
            std::string w;
            std::cin >> w;
            set_a.insert(w);
        }

        std::vector<std::string> b_words(n2);
        for (int i = 0; i < n2; ++i) {
            std::cin >> b_words[i];
        }

        std::unordered_set<std::string> generated_b_set;
        std::queue<std::string> q;
        std::vector<std::string> generated_b_list;

        for (const std::string& w : b_words) {
            if (w.length() <= 40) {
                if (generated_b_set.find(w) == generated_b_set.end()) {
                    generated_b_set.insert(w);
                    q.push(w);
                }
            }
        }
        
        while (!q.empty()) {
            std::string current = q.front();
            q.pop();
            generated_b_list.push_back(current);

            for (const std::string& w : b_words) {
                std::string next_s = current + w;
                if (next_s.length() <= 40) {
                    if (generated_b_set.find(next_s) == generated_b_set.end()) {
                        generated_b_set.insert(next_s);
                        q.push(next_s);
                    }
                }
            }
        }
        
        bool found = false;
        for (const std::string& s : generated_b_list) {
            int n = s.length();
            std::vector<bool> dp(n + 1, false);
            dp[0] = true;

            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (dp[j]) {
                        if (set_a.count(s.substr(j, i - j))) {
                            dp[i] = true;
                            break;
                        }
                    }
                }
            }
            
            if (dp[n]) {
                found = true;
                break;
            }
        }

        if (found) {
            std::cout << "S\n";
        } else {
            std::cout << "N\n";
        }
    }
    return 0;
}
