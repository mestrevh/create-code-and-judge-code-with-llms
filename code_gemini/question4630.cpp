/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, n2;
    std::cin >> n;
    std::vector<int> list1(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> list1[i];
    }
    std::cin >> n2;
    std::vector<int> list2(n2);
    for (int i = 0; i < n2; ++i) {
        std::cin >> list2[i];
    }
    std::vector<int> combinedList;
    combinedList.reserve(n + n2);
    combinedList.insert(combinedList.end(), list1.begin(), list1.end());
    combinedList.insert(combinedList.end(), list2.begin(), list2.end());
    std::sort(combinedList.begin(), combinedList.end());
    combinedList.erase(std::unique(combinedList.begin(), combinedList.end()), combinedList.end());
    std::cout << "[";
    for (size_t i = 0; i < combinedList.size(); ++i) {
        std::cout << combinedList[i];
        if (i < combinedList.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
    return 0;
}

