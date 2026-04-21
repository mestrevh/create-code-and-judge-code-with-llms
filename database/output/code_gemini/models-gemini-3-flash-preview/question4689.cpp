/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>

void bubble_sort(std::vector<int>& v) {
    int n = v.size();
    if (n == 0) return;
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
    
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (v[i] > v[i+1]) {
                std::swap(v[i], v[i+1]);
                swapped = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            std::cout << v[i] << " ";
        }
        std::cout << "\n";
    } while (swapped);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<int> v;
    int x;
    while (std::cin >> x) {
        v.push_back(x);
    }
    
    if (!v.empty()) {
        bubble_sort(v);
    }
    
    return 0;
}