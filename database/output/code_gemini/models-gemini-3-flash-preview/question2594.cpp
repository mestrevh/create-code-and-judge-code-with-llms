/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/**
 * Merge Sort implementation:
 * - Strategy: Divide and Conquer
 * - Stability: Stable
 * - Space: O(n) "not in-place"
 * - Time: O(n log n)
 */
void merge(int* a, int* tmp, int l, int m, int r) {
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }
    while (i < m) tmp[k++] = a[i++];
    while (j < r) tmp[k++] = a[j++];
    for (int p = l; p < r; p++) {
        a[p] = tmp[p];
    }
}

void merge_sort(int* a, int* tmp, int l, int r) {
    if (r - l <= 1) return;
    int m = l + (r - l) / 2;
    merge_sort(a, tmp, l, m);
    merge_sort(a, tmp, m, r);
    merge(a, tmp, l, m, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line)) return 0;

    stringstream ss(line);
    vector<int> arr;
    int val;
    while (ss >> val) {
        arr.push_back(val);
    }

    if (arr.empty()) {
        return 0;
    }

    int n = static_cast<int>(arr.size());
    vector<int> tmp(n);
    merge_sort(arr.data(), tmp.data(), 0, n);

    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    return 0;
}