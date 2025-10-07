/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

long long merge_and_count(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inv_count = 0;

    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (long long)(mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

long long merge_sort_and_count(std::vector<int>& arr, std::vector<int>& temp, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inv_count += merge_sort_and_count(arr, temp, left, mid);
        inv_count += merge_sort_and_count(arr, temp, mid + 1, right);
        inv_count += merge_and_count(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        std::vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> p[i];
        }

        std::vector<int> temp(n);
        long long inversions = merge_sort_and_count(p, temp, 0, n - 1);

        if (inversions % 2 != 0) {
            std::cout << "Marcelo\n";
        } else {
            std::cout << "Carlos\n";
        }
    }

    return 0;
}
