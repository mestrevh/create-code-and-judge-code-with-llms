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
    if (n <= 0) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        cout << a[i] << (i == 0 ? "" : " ");
    }
    cout << "\n";

    for (int i = 0; i < n; ++i) {
        cout << a[(i + 1) % n] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}