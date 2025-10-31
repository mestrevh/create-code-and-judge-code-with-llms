/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
    }
    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();

    for (int i = 0; i < N; ++i) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::vector<int> arr;
        int num;

        while (iss >> num) {
            arr.push_back(num);
        }

        mergeSort(arr, 0, arr.size() - 1);
        
        for (size_t j = 0; j < arr.size(); ++j) {
            std::cout << arr[j];
            if (j < arr.size() - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
