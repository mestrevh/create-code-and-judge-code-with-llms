/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::vector<int>> production(20, std::vector<int>(12));
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 12; ++j) {
            std::cin >> production[i][j];
        }
    }

    int start_month, start_year;
    int end_month, end_year;
    std::cin >> start_month >> start_year;
    std::cin >> end_month >> end_year;

    int start_row = start_year - 2000;
    int start_col = start_month - 1;
    int end_row = end_year - 2000;
    int end_col = end_month - 1;

    long long total_production = 0;

    if (start_row == end_row) {
        for (int j = start_col; j <= end_col; ++j) {
            total_production += production[start_row][j];
        }
    } else {
        for (int j = start_col; j < 12; ++j) {
            total_production += production[start_row][j];
        }

        for (int i = start_row + 1; i < end_row; ++i) {
            for (int j = 0; j < 12; ++j) {
                total_production += production[i][j];
            }
        }

        for (int j = 0; j <= end_col; ++j) {
            total_production += production[end_row][j];
        }
    }

    std::cout << total_production << std::endl;

    return 0;
}
