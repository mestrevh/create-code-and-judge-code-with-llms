/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    int last_pivot_col = -1;
    bool found_zero_row = false;
    char ans = 'S';

    for (int i = 0; i < n; ++i) {
        int current_pivot_col = -1;
        bool is_current_row_zero = true;

        for (int j = 0; j < m; ++j) {
            int val;
            std::cin >> val;
            if (val != 0 && is_current_row_zero) {
                current_pivot_col = j;
                is_current_row_zero = false;
            }
        }

        if (is_current_row_zero) {
            found_zero_row = true;
        } else {
            if (found_zero_row) {
                ans = 'N';
            }
            if (current_pivot_col <= last_pivot_col) {
                ans = 'N';
            }
            last_pivot_col = current_pivot_col;
        }
    }

    std::cout << ans;

    return 0;
}
