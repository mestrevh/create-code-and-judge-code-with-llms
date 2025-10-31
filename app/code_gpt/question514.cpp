/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> left(arr.begin() + start, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + end + 1);
    int i = left.size() - 1, j = right.size() - 1, k = end;

    while (i >= 0 && j >= 0) {
        if (left[i] >= right[j]) {
            arr[k--] = left[i--];
        } else {
            arr[k--] = right[j--];
        }
    }
    while (i >= 0) arr[k--] = left[i--];
    while (j >= 0) arr[k--] = right[j--];
}

void bottom_up_merge_sort(vector<int>& arr) {
    int n = arr.size();
    for (int size = 1; size < n; size *= 2) {
        for (int start = 0; start < n; start += 2 * size) {
            int mid = min(start + size - 1, n - 1);
            int end = min(start + 2 * size - 1, n - 1);
            merge(arr, start, mid, end);
        }
        for (int k = 0; k < n; k++) {
            if (k > 0) cout << " ";
            cout << arr[k];
        }
        cout << " |";
        cout << endl;
    }
}

vector<int> generate_array(int n, int x0, int a, int c, int m) {
    vector<int> arr(n);
    arr[0] = x0;
    for (int j = 1; j < n; j++) {
        arr[j] = (a * arr[j - 1] + c) % m;
    }
    return arr;
}

int main() {
    int n, x0, a, c, m;
    while (cin >> n >> x0 >> a >> c >> m) {
        auto arr = generate_array(n, x0, a, c, m);
        bottom_up_merge_sort(arr);
        cout << endl;
    }
    return 0;
}
