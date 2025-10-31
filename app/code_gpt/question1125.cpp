/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

void generateParenthesis(int left, int right, std::string current, std::vector<std::string>& result) {
    if (left == 0 && right == 0) {
        result.push_back(current);
        return;
    }
    if (left > 0) generateParenthesis(left - 1, right, current + "(", result);
    if (right > left) generateParenthesis(left, right - 1, current + ")", result);
}

int main() {
    int N;
    std::cin >> N;
    std::vector<std::string> result;
    generateParenthesis(N, N, "", result);
    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i != result.size() - 1) std::cout << ", ";
    }
    std::cout << "]";
    return 0;
}
