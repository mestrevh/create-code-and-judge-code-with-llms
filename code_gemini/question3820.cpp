/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::map<char, int> category_totals;
    long long grand_total = 0;

    for (int i = 0; i < n; ++i) {
        char category;
        int value;
        std::cin >> category >> value;
        category_totals[category] += value;
        grand_total += value;
    }

    for (const auto& pair : category_totals) {
        std::cout << pair.first << " " << pair.second << '\n';
    }

    std::cout << "TOTAL " << grand_total << '\n';

    return 0;
}
