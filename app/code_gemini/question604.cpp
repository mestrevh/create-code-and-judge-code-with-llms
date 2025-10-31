/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int c, n;
    std::cin >> c >> n;

    int s = c / n;
    
    std::map<int, std::vector<int>> rem_to_qs;
    std::map<int, int> i_freq;

    for (int i = 0; i < n; ++i) {
        int olive_pos;
        std::cin >> olive_pos;
        int q = olive_pos / s;
        int r = olive_pos % s;
        rem_to_qs[r].push_back(q);
        i_freq[q]++;
    }

    auto check = [&](const std::map<int, int>& freq) {
        if (freq.size() != n) {
            return false;
        }
        int min_i = freq.begin()->first;
        int max_i = freq.rbegin()->first;
        return (max_i - min_i + 1 == n);
    };

    if (check(i_freq)) {
        std::cout << "S\n";
        return 0;
    }

    for (const auto& pair : rem_to_qs) {
        const std::vector<int>& qs = pair.second;
        for (int q : qs) {
            i_freq[q]--;
            if (i_freq[q] == 0) {
                i_freq.erase(q);
            }
            i_freq[q - 1]++;
        }
        if (check(i_freq)) {
            std::cout << "S\n";
            return 0;
        }
    }

    std::cout << "N\n";

    return 0;
}
