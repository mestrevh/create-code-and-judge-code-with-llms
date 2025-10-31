/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

long long merge_and_count(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> left_sub(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> right_sub(arr.begin() + mid + 1, arr.begin() + right + 1);

    long long inversions = 0;
    int i = 0, j = 0, k = left;
    int n1 = left_sub.size();
    int n2 = right_sub.size();

    while (i < n1 && j < n2) {
        if (left_sub[i] <= right_sub[j]) {
            arr[k++] = left_sub[i++];
        } else {
            arr[k++] = right_sub[j++];
            inversions += (n1 - i);
        }
    }

    while (i < n1) {
        arr[k++] = left_sub[i++];
    }

    while (j < n2) {
        arr[k++] = right_sub[j++];
    }

    return inversions;
}

long long merge_sort_and_count(std::vector<int>& arr, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inversions += merge_sort_and_count(arr, left, mid);
        inversions += merge_sort_and_count(arr, mid + 1, right);
        inversions += merge_and_count(arr, left, mid, right);
    }
    return inversions;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> r[i];
    }

    long long result = merge_sort_and_count(r, 0, n - 1);

    std::cout << result << std::endl;

    return 0;
}
