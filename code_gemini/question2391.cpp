/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int n, m;
std::string s;
int s_idx;
std::vector<std::vector<int>> bitmap;

void fill_bitmap(int r_start, int c_start, int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        return;
    }

    char current_char = s[s_idx++];

    if (current_char == 'D') {
        int r1 = (rows + 1) / 2;
        int r2 = rows / 2;
        int c1 = (cols + 1) / 2;
        int c2 = cols / 2;

        fill_bitmap(r_start, c_start, r1, c1);
        fill_bitmap(r_start, c_start + c1, r1, c2);
        fill_bitmap(r_start + r1, c_start, r2, c1);
        fill_bitmap(r_start + r1, c_start + c1, r2, c2);
    } else {
        int val = current_char - '0';
        for (int i = r_start; i < r_start + rows; ++i) {
            for (int j = c_start; j < c_start + cols; ++j) {
                bitmap[i][j] = val;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    if (!(std::cin >> T)) {
        return 0;
    }

    while (T--) {
        std::cin >> n >> m;
        std::cin >> s;
        
        s_idx = 0;
        bitmap.assign(n, std::vector<int>(m));
        
        fill_bitmap(0, 0, n, m);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << bitmap[i][j];
            }
            std::cout << "\n";
        }
        
        if (T > 0) {
            std::cout << "\n";
        }
    }

    return 0;
}
