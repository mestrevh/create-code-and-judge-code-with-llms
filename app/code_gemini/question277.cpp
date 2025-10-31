/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <tuple>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n < 3) {
        return 0;
    }

    std::vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> elements[i];
        if (elements[i] < 0) {
            std::cout << "-1\n";
            return 0;
        }
    }

    std::map<int, int> sum_counts;
    std::vector<std::tuple<int, int, int>> subsets;

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int e1 = elements[i];
                int e2 = elements[j];
                int e3 = elements[k];
                
                int current_sum = e1 + e2 + e3;
                sum_counts[current_sum]++;
                subsets.emplace_back(e1, e2, e3);
            }
        }
    }

    for (const auto& subset : subsets) {
        int e1 = std::get<0>(subset);
        int e2 = std::get<1>(subset);
        int e3 = std::get<2>(subset);
        
        int current_sum = e1 + e2 + e3;
        
        if (sum_counts[current_sum] == 1) {
            std::cout << "{" << e1 << "," << e2 << "," << e3 << "} = " << current_sum << "\n";
        }
    }

    return 0;
}
