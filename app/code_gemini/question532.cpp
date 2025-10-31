/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int compare_and_count(const std::string& s1, const std::string& s2, long long& comparisons) {
    int len1 = s1.length();
    int len2 = s2.length();
    int min_len = std::min(len1, len2);
    for (int i = 0; i < min_len; ++i) {
        comparisons++;
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    
    if (len1 == len2) {
        return 0;
    }
    return len1 - len2;
}

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

        long long total_comparisons = 0;
        bool found = false;
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            int cmp_result = compare_and_count(query, dictionary[mid], total_comparisons);
            
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
