/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> arr1(20), arr2(20);
    std::set<int> intersection;
    
    for (int i = 0; i < 20; ++i) {
        std::cin >> arr1[i];
    }
    for (int i = 0; i < 20; ++i) {
        std::cin >> arr2[i];
    }

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (arr1[i] == arr2[j]) {
                intersection.insert(arr1[i]);
            }
        }
    }

    if (intersection.empty()) {
        std::cout << "VAZIO" << std::endl;
    } else {
        std::vector<int> result(intersection.begin(), intersection.end());
        std::sort(result.begin(), result.end());
        for (int num : result) {
            std::cout << num << std::endl;
        }
    }

    return 0;
}
