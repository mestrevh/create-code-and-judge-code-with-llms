/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Merges two sorted halves and counts the number of inversions.
 * An inversion is a pair (i, j) such that i < j and A[i] > A[j].
 */
long long merge_and_count(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid;     // Starting index for right subarray
    int k = left;    // Starting index for to be sorted subarray
    long long inv_count = 0;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // Since subarrays are sorted, all elements from i to mid-1 are greater than arr[j]
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    // Copy remaining elements of left subarray, if any
    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right subarray, if any
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back the merged elements to original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

/**
 * Recursive function that sorts the array and returns the inversion count.
 */
long long merge_sort(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long inv_count = 0;
    if (right > left) {
        int mid = left + (right - left) / 2;

        // Inversion count is sum of inversions in left-part, right-part and merge-part
        inv_count += merge_sort(arr, temp, left, mid);
        inv_count += merge_sort(arr, temp, mid + 1, right);

        inv_count += merge_and_count(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    if (n <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> temp(n);
    long long result = merge_sort(arr, temp, 0, n - 1);

    cout << result << endl;

    return 0;
}