/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int invCount = 0;
    vector<int> temp(right - left + 1);

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    return invCount;
}

int mergeSortAndCount(vector<int>& arr, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        invCount += mergeSortAndCount(arr, left, mid);
        invCount += mergeSortAndCount(arr, mid + 1, right);
        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
}

int main() {
    int n;
    cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    cout << mergeSortAndCount(r, 0, n - 1) << endl;
    return 0;
}
