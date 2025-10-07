/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int count = 0;
    int i = left, j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            count += (mid - i + 1);
        }
    }
    
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }

    return count;
}

int mergeSortAndCount(vector<int>& arr, int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += mergeSortAndCount(arr, left, mid);
        count += mergeSortAndCount(arr, mid + 1, right);
        count += mergeAndCount(arr, left, mid, right);
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = mergeSortAndCount(arr, 0, n - 1);
    cout << result << endl;
    return 0;
}
