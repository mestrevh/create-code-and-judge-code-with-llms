/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool can_cut(int slice_size, int n, const vector<int>& m) {
    int count = 0;
    for (int bread_size : m) {
        count += bread_size / slice_size;
    }
    return count >= n;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> m(k);
    for (int i = 0; i < k; ++i) {
        cin >> m[i];
    }

    int low = 1, high = *max_element(m.begin(), m.end());
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can_cut(mid, n, m)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
