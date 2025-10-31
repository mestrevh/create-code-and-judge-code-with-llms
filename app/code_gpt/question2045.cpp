/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

long long merge_and_count(vector<int>& arr, int left, int mid, int right) {
    int i = left, j = mid, k = 0;
    long long inv_count = 0;
    vector<int> temp(right - left + 1);

    while (i < mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }

    while (i < mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) arr[i] = temp[i - left];

    return inv_count;
}

long long merge_sort_and_count(vector<int>& arr, int left, int right) {
    long long inv_count = 0;
    if (right > left) {
        int mid = (left + right) / 2;

        inv_count += merge_sort_and_count(arr, left, mid);
        inv_count += merge_sort_and_count(arr, mid + 1, right);
        inv_count += merge_and_count(arr, left, mid + 1, right);
    }
    return inv_count;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        if (t) cin.ignore();
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << merge_sort_and_count(arr, 0, n - 1) << endl;
    }
    return 0;
}
