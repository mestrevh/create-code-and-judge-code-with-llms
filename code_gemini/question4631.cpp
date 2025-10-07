/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void print_vector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<int, int> counts;
    int n, n2, num;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        counts[num]++;
    }

    std::cin >> n2;
    for (int i = 0; i < n2; ++i) {
        std::cin >> num;
        counts[num]++;
    }

    std::vector<int> repeated_list;
    std::vector<int> all_unique_list;
    std::vector<int> unique_only_list;

    for (const auto& pair : counts) {
        all_unique_list.push_back(pair.first);
        if (pair.second > 1) {
            repeated_list.push_back(pair.first);
        } else {
            unique_only_list.push_back(pair.first);
        }
    }

    print_vector(repeated_list);
    print_vector(all_unique_list);
    print_vector(unique_only_list);

    return 0;
}
