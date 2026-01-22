/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

void print_subset(const std::vector<int>& subset) {
    std::cout << "{";
    for (int x : subset) {
        std::cout << " " << x;
    }
    std::cout << " }\n";
}

void generate_subsets(int k, int n, std::vector<int>& current_subset) {
    if (k > n) {
        print_subset(current_subset);
        return;
    }

    current_subset.push_back(k);
    generate_subsets(k + 1, n, current_subset);
    current_subset.pop_back();

    generate_subsets(k + 1, n, current_subset);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> subset;
    generate_subsets(1, n, subset);

    return 0;
}
