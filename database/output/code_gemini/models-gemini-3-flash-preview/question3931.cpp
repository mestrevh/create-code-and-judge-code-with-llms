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

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) return 0;

    vector<int> a(n);
    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        if (!(cin >> a[i])) break;
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }

    vector<int> c(max_val + 1, 0);
    for (int i = 0; i < n; ++i) {
        c[a[i]]++;
    }

    for (int i = 0; i <= max_val; ++i) {
        cout << c[i] << " ";
    }
    cout << "\n";

    bool first = true;
    for (int i = 0; i <= max_val; ++i) {
        for (int j = 0; j < c[i]; ++j) {
            if (!first) {
                cout << " ";
            }
            cout << i;
            first = false;
        }
    }
    cout << "\n";

    return 0;
}