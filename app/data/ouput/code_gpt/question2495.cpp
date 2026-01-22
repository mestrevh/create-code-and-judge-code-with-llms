/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> heights[i];
    }
    std::sort(heights.begin(), heights.end());
    int additional_statues = 0;
    for (int i = 1; i < n; ++i) {
        int diff = heights[i] - heights[i - 1];
        if (diff > 1) {
            additional_statues += diff - 1;
        }
    }
    std::cout << additional_statues << std::endl;
    return 0;
}
