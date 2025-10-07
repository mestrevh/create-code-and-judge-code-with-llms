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

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> dictionary(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> dictionary[i];
    }

    for (int i = 0; i < m; ++i) {
        std::string query;
        std::cin >> query;

        int l = 0;
        int r = n - 1;
        bool found = false;
        long long total_comparisons = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            const std::string& target = dictionary[mid];
            
            int cmp_result = 0;
            size_t len_min = std::min(query.length(), target.length());

            for (size_t k = 0; k < len_min; ++k) {
                total_comparisons++;
                if (query[k] != target[k]) {
                    cmp_result = (query[k] < target[k]) ? -1 : 1;
                    break;
                }
            }

            if (cmp_result == 0) {
                if (query.length() < target.length()) {
                    cmp_result = -1;
                } else if (query.length() > target.length()) {
                    cmp_result = 1;
                }
            }

            if (cmp_result == 0) {
                found = true;
                break;
            } else if (cmp_result < 0) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (found) {
            std::cout << "SIM " << total_comparisons << "\n";
        } else {
            std::cout << "NAO " << total_comparisons << "\n";
        }
    }

    return 0;
}
