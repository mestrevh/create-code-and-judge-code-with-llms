/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

long long merge(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inv_count = 0;

    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
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

long long count_inversions_helper(std::vector<int>& arr, std::vector<int>& temp, int left, int right) {
    long long inv_count = 0;
    if (right > left) {
        int mid = left + (right - left) / 2;
        inv_count += count_inversions_helper(arr, temp, left, mid);
        inv_count += count_inversions_helper(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

long long count_inversions(std::vector<int>& arr) {
    if (arr.size() < 2) return 0;
    std::vector<int> temp(arr.size());
    return count_inversions_helper(arr, temp, 0, arr.size() - 1);
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

        long long inversions = count_inversions(p);

        if (inversions % 2 == 0) {
            std::cout << "Carlos\n";
        } else {
            std::cout << "Marcelo\n";
        }
    }

    return 0;
}
