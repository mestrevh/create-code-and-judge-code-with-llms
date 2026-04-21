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

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int m;
    if (!(cin >> m)) {
        cout << 1 << endl;
        return 0;
    }

    bool is_subset = true;
    for (int i = 0; i < m; ++i) {
        int val;
        cin >> val;
        if (is_subset) {
            if (!binary_search(a.begin(), a.end(), val)) {
                is_subset = false;
            }
        }
    }

    if (is_subset) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}