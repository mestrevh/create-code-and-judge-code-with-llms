/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <functional>

void generateParentheses(int n, int open, int close, std::string current, std::vector<std::string>& result) {
    if (current.length() == n * 2) {
        result.push_back(current);
        return;
    }

    if (open < n) {
        generateParentheses(n, open + 1, close, current + "(", result);
    }

    if (close < open) {
        generateParentheses(n, open, close + 1, current + ")", result);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "[]\n";
        return 0;
    }

    std::vector<std::string> combinations;
    generateParentheses(n, 0, 0, "", combinations);

    std::cout << "[";
    for (size_t i = 0; i < combinations.size(); ++i) {
        std::cout << combinations[i];
        if (i < combinations.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]\n";

    return 0;
}
