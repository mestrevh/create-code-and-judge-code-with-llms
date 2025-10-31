/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stack>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double c;
    std::cin >> c;

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << std::fixed << std::setprecision(2) << 0.0 << std::endl;
        return 0;
    }

    std::vector<double> rates(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> rates[i];
        rates[i] /= 100.0;
    }

    std::vector<int> left(n);
    std::stack<int> s1;
    for (int i = 0; i < n; ++i) {
        while (!s1.empty() && rates[s1.top()] >= rates[i]) {
            s1.pop();
        }
        left[i] = s1.empty() ? -1 : s1.top();
        s1.push(i);
    }

    std::vector<int> right(n);
    std::stack<int> s2;
    for (int i = n - 1; i >= 0; --i) {
        while (!s2.empty() && rates[s2.top()] >= rates[i]) {
            s2.pop();
        }
        right[i] = s2.empty() ? n : s2.top();
        s2.push(i);
    }

    double max_profit_factor = 0.0;
    for (int i = 0; i < n; ++i) {
        double width = static_cast<double>(right[i] - left[i] - 1);
        max_profit_factor = std::max(max_profit_factor, rates[i] * width);
    }

    double max_profit = c * max_profit_factor;
    std::cout << std::fixed << std::setprecision(2) << max_profit << std::endl;

    return 0;
}
