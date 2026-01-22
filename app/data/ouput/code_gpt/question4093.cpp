/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>

void buscaBinaria(const std::vector<int>& arr, int k, int left, int right) {
    if (left > right) {
        std::cout << "[";
        for (size_t i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
        }
        std::cout << "]  ---->  -1\n";
        return;
    }
    int mid = left + (right - left) / 2;
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    std::cout << "]  ---->  " << arr[mid] << "\n";

    if (arr[mid] == k) return;
    if (arr[mid] > k)
        buscaBinaria(arr, k, left, mid - 1);
    else
        buscaBinaria(arr, k, mid + 1, right);
}

int main() {
    int k, n;
    std::cin >> k >> n;
    std::cin.ignore();
    std::string line;
    std::getline(std::cin, line);
    
    std::vector<int> arr;
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, ',')) {
        arr.push_back(std::stoi(item));
    }
    
    buscaBinaria(arr, k, 0, n - 1);
    return 0;
}
