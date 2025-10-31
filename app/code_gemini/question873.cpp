/*
Código criado pelo Gemini Pro 2.5
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

    while (i <= mid && j <= right) {
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

    for (int l = left; l <= right; ++l) {
        arr[l] = temp[l];
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
    long long m;
    std::cin >> n >> m;

    std::vector<int> v_orig(n);
    std::vector<int> v_sort(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v_orig[i];
        v_sort[i] = v_orig[i];
    }

    long long I = 0;
    if (n > 0) {
        std::vector<int> temp(n);
        I = merge_sort_and_count(v_sort, temp, 0, n - 1);
    }

    std::vector<bool> occupied(m, false);

    for (int i = 0; i < n; ++i) {
        long long val = v_orig[i];
        long long pos = val % m;
        
        if (I == 0 && occupied[pos]) {
           I = 1;
        }

        while (occupied[pos]) {
            pos = (pos + I) % m;
        }

        occupied[pos] = true;
        std::cout << pos << "\n";
    }

    return 0;
}
