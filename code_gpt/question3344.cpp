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
    std::vector<int> arr(n), sortedArr(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        sortedArr[i] = arr[i];
    }
    
    std::sort(sortedArr.begin(), sortedArr.end());
    
    std::vector<std::pair<int, int>> result;
    
    for (int i = 0; i < n; ++i) {
        if (arr[i] == sortedArr[i]) {
            result.emplace_back(arr[i], i + 1);
        }
    }
    
    std::cout << result.size() << "\n";
    for (const auto& [value, index] : result) {
        std::cout << value << " " << index << "\n";
    }
    
    return 0;
}
