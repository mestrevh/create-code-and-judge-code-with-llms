/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool is_palindrome(const std::string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (c + k <= n) {
                std::string horizontal_sub = grid[r].substr(c, k);
                if (is_palindrome(horizontal_sub)) {
                    std::cout << "(" << r + 1 << ", " << c + 1 << ")\n";
                    return 0;
                }
            }

            if (r + k <= n) {
                std::string vertical_sub;
                vertical_sub.reserve(k);
                for (int i = 0; i < k; ++i) {
                    vertical_sub += grid[r + i][c];
                }
                if (is_palindrome(vertical_sub)) {
                    std::cout << "(" << r + 1 << ", " << c + 1 << ")\n";
                    return 0;
                }
            }
        }
    }

    std::cout << "(-1, -1)\n";

    return 0;
}
