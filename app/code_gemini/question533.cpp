/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>
#include <tuple>
#include <algorithm>

class HashSet {
private:
    std::vector<std::list<int>> table;
    int m;
    int n;

    int hash_function(int k) const {
        return k % m;
    }

    void rehash() {
        int old_m = m;
        std::vector<std::list<int>> old_table = std::move(table);

        m = 2 * old_m - 1;
        table.assign(m, std::list<int>());

        for (int i = 0; i < old_m; ++i) {
            for (auto it = old_table[i].rbegin(); it != old_table[i].rend(); ++it) {
                int val = *it;
                int new_idx = hash_function(val);
                table[new_idx].push_front(val);
            }
        }
    }

public:
    HashSet() : m(7), n(0) {
        table.resize(m);
    }

    std::pair<bool, int> add(int k) {
        int idx = hash_function(k);
        int comparisons = 0;
        for (const auto& val : table[idx]) {
            comparisons++;
            if (val == k) {
                return {false, comparisons};
            }
        }
        
        table[idx].push_front(k);
        n++;

        if (4 * n >= 3 * m) {
            rehash();
        }

        return {true, comparisons};
    }

    std::pair<bool, int> del(int k) {
        int idx = hash_function(k);
        int comparisons = 0;
        auto& bucket = table[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            comparisons++;
            if (*it == k) {
                bucket.erase(it);
                n--;
                return {true, comparisons};
            }
        }
        return {false, comparisons};
    }

    std::pair<bool, int> has(int k) const {
        int idx = hash_function(k);
        int comparisons = 0;
        for (const auto& val : table[idx]) {
            comparisons++;
            if (val == k) {
                return {true, comparisons};
            }
        }
        return {false, comparisons};
    }

    std::tuple<int, int, int> get_stats() const {
        size_t max_len = 0;
        for (const auto& bucket : table) {
            max_len = std::max(max_len, bucket.size());
        }
        return {m, n, static_cast<int>(max_len)};
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    HashSet hs;
    std::string command;
    int k;
    int op_count = 0;

    while (std::cin >> command) {
        if (command == "ADD") {
            std::cin >> k;
            auto result = hs.add(k);
            std::cout << op_count << " " << (result.first ? 1 : 0) << " " << result.second << "\n";
        } else if (command == "DEL") {
            std::cin >> k;
            auto result = hs.del(k);
            std::cout << op_count << " " << (result.first ? 1 : 0) << " " << result.second << "\n";
        } else if (command == "HAS") {
            std::cin >> k;
            auto result = hs.has(k);
            std::cout << op_count << " " << (result.first ? 1 : 0) << " " << result.second << "\n";
        } else if (command == "PRT") {
            auto stats = hs.get_stats();
            std::cout << op_count << " " << std::get<0>(stats) << " " << std::get<1>(stats) << " " << std::get<2>(stats) << "\n";
        }
        op_count++;
    }

    return 0;
}
