/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

void merge_and_print(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    std::vector<int> merged;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            merged.push_back(L[i++]);
        } else {
            merged.push_back(R[j++]);
        }
    }
    while (i < n1) merged.push_back(L[i++]);
    while (j < n2) merged.push_back(R[j++]);

    for (int m : merged) arr[k++] = m;

    for (int m : merged) std::cout << m << ' ';
    std::cout << std::endl;
}

void merge_sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge_and_print(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> arr;
    int num;
    while (std::cin >> num) arr.push_back(num);
    
    merge_sort(arr, 0, arr.size() - 1);
    
    for (int x : arr) std::cout << x << ' ';
    std::cout << std::endl;
    
    return 0;
}
