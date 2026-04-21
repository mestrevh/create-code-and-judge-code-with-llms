/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            int n, d;
            if (!(cin >> n >> d)) break;
            vector<int> a(n);
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            sort(a.begin(), a.end());
            if (a[n - 1] <= d || a[0] + a[1] <= d) {
                cout << "SIM\n";
            } else {
                cout << "NAO\n";
            }
        }
    }

    return 0;
}