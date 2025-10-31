/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

long long calculate_hash(const std::string& s, int base, int mod) {
    long long hash_val = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_val = (hash_val + (long long)c * p_pow) % mod;
        p_pow = (p_pow * base) % mod;
    }
    return hash_val;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::unordered_set<std::string> original_strings;
    std::vector<std::string> strings_to_add(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> strings_to_add[i];
        original_strings.insert(strings_to_add[i]);
    }

    int m, k;
    std::cin >> m >> k;

    std::vector<int> bases(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> bases[i];
    }

    std::vector<bool> bloom_filter(m, false);

    for (const auto& s : strings_to_add) {
        for (int base : bases) {
            long long h = calculate_hash(s, base, m);
            bloom_filter[h] = true;
        }
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; ++i) {
        std::string t;
        std::cin >> t;

        bool bloom_says_present = true;
        for (int base : bases) {
            long long h = calculate_hash(t, base, m);
            if (!bloom_filter[h]) {
                bloom_says_present = false;
                break;
            }
        }

        if (!bloom_says_present) {
            std::cout << 0 << "\n";
        } else {
            if (original_strings.count(t) > 0) {
                std::cout << 2 << "\n";
            } else {
                std::cout << 1 << "\n";
            }
        }
    }

    return 0;
}
