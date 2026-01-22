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

    int k, n, m;
    std::cin >> k;
    std::cin >> n >> m;
    std::vector<std::string> auditorium(n);
    int total_empty_seats = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> auditorium[i];
        for (char c : auditorium[i]) {
            if (c == 'o') {
                total_empty_seats++;
            }
        }
    }

    int best_row = -1;
    int best_col = -1;
    bool found_block = false;

    if (k <= m) {
        for (int i = 0; i < n; ++i) {
            for (int j = m - k; j >= 0; --j) {
                bool is_block_valid = true;
                for (int l = 0; l < k; ++l) {
                    if (auditorium[i][j + l] != 'o') {
                        is_block_valid = false;
                        break;
                    }
                }
                if (is_block_valid) {
                    best_row = i;
                    best_col = j;
                    found_block = true;
                    break;
                }
            }
            if (found_block) {
                break;
            }
        }
    }

    if (found_block) {
        std::cout << "Todos sentados e juntos\n";
        for (int l = 0; l < k; ++l) {
            auditorium[best_row][best_col + l] = '*';
        }
        for (int i = 0; i < n; ++i) {
            std::cout << auditorium[i] << '\n';
        }
    } else {
        if (total_empty_seats >= k) {
            std::cout << "Todos sentados, mas separados\n";
            int seats_to_fill = k;
            for (int i = 0; i < n && seats_to_fill > 0; ++i) {
                for (int j = m - 1; j >= 0 && seats_to_fill > 0; --j) {
                    if (auditorium[i][j] == 'o') {
                        auditorium[i][j] = '*';
                        seats_to_fill--;
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                std::cout << auditorium[i] << '\n';
            }
        } else {
            std::cout << total_empty_seats << " sentados, " << (k - total_empty_seats) << " em pé\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (auditorium[i][j] == 'o') {
                        auditorium[i][j] = '*';
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                std::cout << auditorium[i] << '\n';
            }
        }
    }

    return 0;
}
