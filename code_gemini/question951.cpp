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

    int T;
    std::cin >> T;

    int star_row = -1;
    int star_col = -1;

    for (int i = 0; i < T; ++i) {
        std::string row_str;
        std::cin >> row_str;
        if (star_row == -1) {
            size_t pos = row_str.find('*');
            if (pos != std::string::npos) {
                star_row = i;
                star_col = static_cast<int>(pos);
            }
        }
    }

    int current_row_start = 0;
    int current_col_start = 0;
    int current_size = T;

    while (current_size > 1) {
        int mid_row = current_row_start + current_size / 2;
        int mid_col = current_col_start + current_size / 2;

        if (star_row < mid_row) { // Top half
            if (star_col < mid_col) { // Quadrant 2 (Top-Left)
                std::cout << '2';
            } else { // Quadrant 1 (Top-Right)
                std::cout << '1';
                current_col_start = mid_col;
            }
        } else { // Bottom half
            if (star_col < mid_col) { // Quadrant 3 (Bottom-Left)
                std::cout << '3';
                current_row_start = mid_row;
            } else { // Quadrant 4 (Bottom-Right)
                std::cout << '4';
                current_row_start = mid_row;
                current_col_start = mid_col;
            }
        }
        current_size /= 2;
    }

    std::cout << '0' << std::endl;

    return 0;
}
