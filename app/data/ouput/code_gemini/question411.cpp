/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

std::string source, target;
std::vector<std::string> solutions;
std::stack<char> s;
std::vector<char> path;

void find_sequences(int src_idx, int tgt_idx) {
    if (tgt_idx == target.length()) {
        std::string result;
        if (!path.empty()) {
            result += path[0];
            for (size_t i = 1; i < path.size(); ++i) {
                result += ' ';
                result += path[i];
            }
        }
        solutions.push_back(result);
        return;
    }

    if (src_idx < source.length()) {
        s.push(source[src_idx]);
        path.push_back('i');
        find_sequences(src_idx + 1, tgt_idx);
        path.pop_back();
        s.pop();
    }

    if (!s.empty() && s.top() == target[tgt_idx]) {
        char top = s.top();
        s.pop();
        path.push_back('o');
        find_sequences(src_idx, tgt_idx + 1);
        path.pop_back();
        s.push(top);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    while (std::cin >> source >> target) {
        std::cout << "[\n";

        solutions.clear();
        path.clear();
        while (!s.empty()) {
            s.pop();
        }

        if (source.length() == target.length() && !source.empty()) {
            std::string sorted_src = source;
            std::string sorted_tgt = target;
            std::sort(sorted_src.begin(), sorted_src.end());
            std::sort(sorted_tgt.begin(), sorted_tgt.end());
            if (sorted_src == sorted_tgt) {
                find_sequences(0, 0);
            }
        }

        std::sort(solutions.begin(), solutions.end());
        for (const auto& sol : solutions) {
            std::cout << sol << "\n";
        }

        std::cout << "]\n";
    }

    return 0;
}
