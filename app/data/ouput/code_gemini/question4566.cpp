/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<char> chars(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> chars[i];
    }

    int m;
    std::cin >> m;
    std::vector<int> nums(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> nums[i];
    }

    std::vector<char> result;
    int common_len = std::min(n, m);

    for (int i = 0; i < common_len; ++i) {
        char new_char = chars[i] + nums[i];
        if (new_char >= 'a' && new_char <= 'z') {
            result.push_back(new_char);
        } else {
            result.push_back('.');
        }
    }

    if (n > m) {
        for (int i = m; i < n; ++i) {
            result.push_back(chars[i]);
        }
    } else if (m > n) {
        for (int i = n; i < m; ++i) {
            char new_char = 'a' + nums[i];
            if (new_char >= 'a' && new_char <= 'z') {
                result.push_back(new_char);
            } else {
                result.push_back('.');
            }
        }
    }

    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    std::cout << "\n";

    return 0;
}
