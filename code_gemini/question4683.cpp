/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<bool> col_has_white(m, false);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (matrix[i][j] == 1) {
                col_has_white[j] = true;
                break;
            }
        }
    }

    std::vector<std::pair<int, int>> symbol_blocks;
    for (int j = 0; j < m; ++j) {
        if (col_has_white[j]) {
            int start = j;
            while (j + 1 < m && col_has_white[j + 1]) {
                j++;
            }
            int end = j;
            symbol_blocks.push_back({start, end});
        }
    }

    if (!symbol_blocks.empty()) {
        int start_print_col = 0;
        for (size_t i = 0; i < symbol_blocks.size(); ++i) {
            int end_print_col;
            if (i == symbol_blocks.size() - 1) {
                end_print_col = m - 1;
            } else {
                int end_current_symbol = symbol_blocks[i].second;
                int start_next_symbol = symbol_blocks[i + 1].first;
                int gap = start_next_symbol - end_current_symbol - 1;
                int margin = (gap + 1) / 2;
                end_print_col = end_current_symbol + margin;
            }

            for (int row = 0; row < n; ++row) {
                for (int col = start_print_col; col <= end_print_col; ++col) {
                    std::cout << matrix[row][col] << (col == end_print_col ? "" : " ");
                }
                std::cout << '\n';
            }

            start_print_col = end_print_col + 1;

            if (i < symbol_blocks.size() - 1) {
                std::cout << '\n';
            }
        }
    }
    
    std::cout << "Foram encontrados " << symbol_blocks.size() << " simbolos!\n";

    return 0;
}
