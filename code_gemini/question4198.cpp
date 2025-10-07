/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool is_palindrome(const std::string& s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
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

    // Check horizontal
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n - k; ++j) {
            std::string sub = grid[i].substr(j, k);
            if (is_palindrome(sub)) {
                std::cout << "(" << i + 1 << ", " << j + 1 << ")\n";
                return 0;
            }
        }
    }

    // Check vertical
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i <= n - k; ++i) {
            std::string vertical_str;
            vertical_str.reserve(k);
            for (int row_offset = 0; row_offset < k; ++row_offset) {
                vertical_str += grid[i + row_offset][j];
            }
            if (is_palindrome(vertical_str)) {
                std::cout << "(" << i + 1 << ", " << j + 1 << ")\n";
                return 0;
            }
        }
    }

    std::cout << "(-1, -1)\n";

    return 0;
}
