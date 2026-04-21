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
        if (!(cin >> n)) break;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int max_len = 0;
        int best_start = -1;

        for (int i = 0; i < n; ) {
            int start = i;
            int current_len = 1;
            while (i + 1 < n && a[i] > a[i + 1]) {
                i++;
                current_len++;
            }
            
            if (current_len > max_len) {
                max_len = current_len;
                best_start = start;
            }
            
            i++;
        }

        if (max_len < 2) {
            cout << 0 << "\n";
        } else {
            cout << max_len << "\n";
            for (int i = 0; i < max_len; ++i) {
                cout << a[best_start + i] << (i == max_len - 1 ? " " : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}