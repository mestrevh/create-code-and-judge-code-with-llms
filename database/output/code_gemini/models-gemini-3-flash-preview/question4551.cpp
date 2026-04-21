/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll merge_and_count(vector<int>& arr, vector<int>& temp, int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = l;
    ll count = 0;

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= r) {
        temp[k++] = arr[j++];
    }
    for (i = l; i <= r; i++) {
        arr[i] = temp[i];
    }

    return count;
}

ll solve(vector<int>& arr, vector<int>& temp, int l, int r) {
    ll count = 0;
    if (l < r) {
        int mid = l + (r - l) / 2;
        count += solve(arr, temp, l, mid);
        count += solve(arr, temp, mid + 1, r);
        count += merge_and_count(arr, temp, l, mid, r);
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> arr(n);
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i])) break;
    }

    cout << solve(arr, temp, 0, n - 1) << endl;

    return 0;
}