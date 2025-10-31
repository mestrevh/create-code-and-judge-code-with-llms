/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<int> arr(m);

    for (int i = 0; i < m; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < m; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
        for (const auto& num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    std::vector<int> result(arr.end() - n, arr.end());
    std::sort(result.begin(), result.end(), std::greater<int>());
    for (const auto& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
