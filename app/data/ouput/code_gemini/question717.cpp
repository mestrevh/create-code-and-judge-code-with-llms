/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, n;
    std::cin >> m >> n;
    int total_elements = m * n;
    std::vector<int> elements(total_elements);
    for (int i = 0; i < total_elements; ++i) {
        std::cin >> elements[i];
    }
    std::sort(elements.begin(), elements.end());
    int current_index = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << elements[current_index++];
            if (j < n - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}
