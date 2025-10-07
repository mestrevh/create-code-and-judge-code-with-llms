/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int P;
    std::cin >> P;

    for (int k = 0; k < P; ++k) {
        std::vector<std::vector<int>> columns;
        int s;

        while (std::cin >> s) {
            int c;
            std::cin >> c;

            int n = columns.size();

            if (s == 0) {
                columns.insert(columns.begin(), {c});
            } else if (s == n + 1) {
                columns.push_back({c});
            } else {
                int col_idx = s - 1;
                if (columns[col_idx].empty() || columns[col_idx].back() != c) {
                    columns[col_idx].push_back(c);
                } else {
                    while (!columns[col_idx].empty() && columns[col_idx].back() == c) {
                        columns[col_idx].pop_back();
                    }
                    if (columns[col_idx].empty()) {
                        columns.erase(columns.begin() + col_idx);
                    }
                }
            }
        }

        std::cin.clear();
        std::string end_token;
        std::cin >> end_token;

        std::cout << "caso " << k << ":";
        for (const auto& col : columns) {
            std::cout << " " << col.back();
        }
        std::cout << std::endl;
    }

    return 0;
}
