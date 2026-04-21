/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool check(long long mid, int n, int m, const vector<long long>& t) {
    long long current_sum = 0;
    int count = 1;
    for (int i = 0; i < m; ++i) {
        if (t[i] > mid) return false;
        if (current_sum + t[i] > mid) {
            count++;
            current_sum = t[i];
            if (count > n) return false;
        } else {
            current_sum += t[i];
        }
    }
    return count <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> t(m);
    long long low = 0, high = 0;
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
        if (t[i] > low) low = t[i];
        high += t[i];
    }

    long long ans = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, m, t)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}

