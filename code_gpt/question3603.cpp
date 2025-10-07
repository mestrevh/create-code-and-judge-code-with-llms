/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

bool isSorted(const std::vector<int>& arr) {
    return std::is_sorted(arr.begin(), arr.end());
}

std::vector<int> intercala(const std::vector<int>& x, const std::vector<int>& y) {
    if (!isSorted(x) || !isSorted(y)) return {-1};
    
    std::vector<int> z;
    z.reserve(x.size() + y.size());
    
    size_t i = 0, j = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i] < y[j]) {
            z.push_back(x[i++]);
        } else {
            z.push_back(y[j++]);
        }
    }

    while (i < x.size()) z.push_back(x[i++]);
    while (j < y.size()) z.push_back(y[j++]);
    
    return z;
}

int main() {
    std::vector<int> x, y;
    int temp;
    
    while (std::cin.peek() != '\n' && std::cin >> temp) x.push_back(temp);
    std::cin.ignore();
    while (std::cin.peek() != '\n' && std::cin >> temp) y.push_back(temp);

    std::vector<int> result = intercala(x, y);
    
    for (int val : result) {
        std::cout << val << " ";
    }
    
    return 0;
}
