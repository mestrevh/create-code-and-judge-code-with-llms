/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<char, int> domain_counts;
    domain_counts['a'] = 0;
    domain_counts['b'] = 0;
    domain_counts['c'] = 0;

    bool has_valid_mapping = false;

    for (int i = 0; i < 3; ++i) {
        char x, y;
        std::cin >> x >> y;

        bool is_in_A = (x == 'a' || x == 'b' || x == 'c');
        bool is_in_B = (y == 'd' || y == 'e' || y == 'f');

        if (is_in_A && is_in_B) {
            domain_counts[x]++;
            has_valid_mapping = true;
        }
    }

    if (!has_valid_mapping) {
        std::cout << "A ^ B void\n";
        return 0;
    }

    bool is_relation = false;
    for (auto const& pair : domain_counts) {
        if (pair.second > 1) {
            is_relation = true;
            break;
        }
    }

    if (is_relation) {
        std::cout << "A <-> B\n";
        return 0;
    }

    bool is_total = true;
    for (auto const& pair : domain_counts) {
        if (pair.second == 0) {
            is_total = false;
            break;
        }
    }

    if (is_total) {
        std::cout << "A --> B\n";
    } else {
        std::cout << "A +-> B\n";
    }

    return 0;
}
