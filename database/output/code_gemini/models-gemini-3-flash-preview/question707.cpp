/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        long long x;
        if (!(cin >> n >> x)) break;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long current_sum = 0;
        int left = 0;
        bool found = false;

        for (int right = 0; right < n; ++right) {
            current_sum += a[right];

            while (current_sum > x && left < right) {
                current_sum -= a[left];
                left++;
            }

            if (current_sum == x) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}