/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

int largestRectangleArea(std::vector<int>& heights) {
    heights.push_back(0);
    std::stack<int> s;
    int max_area = 0;
    for (int i = 0; i < heights.size(); ++i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            int h = heights[s.top()];
            s.pop();
            int w = s.empty() ? i : i - s.top() - 1;
            max_area = std::max(max_area, h * w);
        }
        s.push(i);
    }
    heights.pop_back();
    return max_area;
}

void solve() {
    std::vector<std::string> matrix;
    std::string line;
    while (std::getline(std::cin, line) && !line.empty()) {
        matrix.push_back(line);
    }

    if (matrix.empty()) {
        std::cout << 0 << std::endl;
        return;
    }

    int n = matrix.size();
    int m = matrix[0].length();

    int max_area = 0;
    std::vector<int> heights(m, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        max_area = std::max(max_area, largestRectangleArea(heights));
    }

    std::cout << max_area << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    std::string dummy;
    std::getline(std::cin, dummy);
    std::getline(std::cin, dummy);

    for (int i = 0; i < t; ++i) {
        if (i > 0) {
            std::cout << std::endl;
        }
        solve();
    }

    return 0;
}
