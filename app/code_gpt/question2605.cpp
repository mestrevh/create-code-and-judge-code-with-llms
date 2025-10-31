/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();
    for (int i = 0; i < N; i++) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::vector<int> arr((std::istream_iterator<int>(iss)), std::istream_iterator<int>());
        quicksort(arr, 0, arr.size() - 1);
        for (int j = 0; j < arr.size(); j++) {
            std::cout << arr[j] << (j < arr.size() - 1 ? " " : "");
        }
        std::cout << std::endl;
    }
    return 0;
}
