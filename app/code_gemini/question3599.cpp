/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int sum = 0;
    int max_len = 0;
    std::unordered_map<int, int> first_occurrence;
    first_occurrence[0] = -1;

    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;

        if (val == 1) {
            sum++;
        } else {
            sum--;
        }

        if (first_occurrence.count(sum - 1)) {
            max_len = std::max(max_len, i - first_occurrence[sum - 1]);
        }

        if (first_occurrence.find(sum) == first_occurrence.end()) {
            first_occurrence[sum] = i;
        }
    }

    std::cout << max_len << std::endl;

    return 0;
}
