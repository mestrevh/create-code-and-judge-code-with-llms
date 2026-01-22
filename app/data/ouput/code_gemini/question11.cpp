/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    while (std::cin >> n >> m && (n != 0 || m != 0)) {
        std::cin.ignore(); 

        std::vector<std::pair<std::string, std::string>> rules;
        rules.reserve(n);

        for (int i = 0; i < n; ++i) {
            std::string rule_line;
            std::getline(std::cin, rule_line);
            size_t arrow_pos = rule_line.find(" -> ");
            std::string from = rule_line.substr(0, arrow_pos);
            std::string to = rule_line.substr(arrow_pos + 4);
            rules.push_back({from, to});
        }

        for (int i = 0; i < m; ++i) {
            std::string text_line;
            std::getline(std::cin, text_line);

            for (const auto& rule : rules) {
                const std::string& from = rule.first;
                const std::string& to = rule.second;
                
                size_t pos = 0;
                while ((pos = text_line.find(from, pos)) != std::string::npos) {
                    text_line.replace(pos, from.length(), to);
                    pos += to.length();
                }
            }
            std::cout << text_line << '\n';
        }
    }

    return 0;
}
