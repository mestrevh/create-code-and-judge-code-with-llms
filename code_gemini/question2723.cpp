/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

void solve(const std::string& current_thief,
           const std::map<std::string, std::string>& rules,
           std::set<std::string>& visited,
           std::vector<std::string>& result) {
    if (visited.count(current_thief)) {
        return;
    }

    visited.insert(current_thief);
    result.push_back(current_thief);

    std::string next_thief = rules.at(current_thief);
    solve(next_thief, rules, visited, result);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::map<std::string, std::string> rules;
    std::string name, destination;
    for (int i = 0; i < n; ++i) {
        std::cin >> name >> destination;
        rules[name] = destination;
    }

    std::string start_name;
    std::cin >> start_name;

    std::set<std::string> visited;
    std::vector<std::string> result;

    solve(start_name, rules, visited, result);

    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
