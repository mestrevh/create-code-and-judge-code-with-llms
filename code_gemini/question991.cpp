/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void print_vector(const std::vector<int>& v) {
    if (v.empty()) {
        std::cout << "\n";
        return;
    }
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << (i == v.size() - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> initial_cells(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> initial_cells[i];
    }
    
    int min_idx = std::min_element(initial_cells.begin(), initial_cells.end()) - initial_cells.begin();

    std::vector<int> cells;
    cells.reserve(n);
    for (int i = 0; i < n; ++i) {
        cells.push_back(initial_cells[(min_idx + i) % n]);
    }
    
    print_vector(cells);

    for (int i = 0; i < q; ++i) {
        int union_idx;
        std::cin >> union_idx;
        
        int current_n = cells.size();
        
        int successor_idx = (union_idx + 1) % current_n;
        
        cells[union_idx] += cells[successor_idx];
        
        cells.erase(cells.begin() + successor_idx);
        
        print_vector(cells);
    }

    return 0;
}
