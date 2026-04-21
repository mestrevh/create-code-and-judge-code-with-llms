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

    if (n <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<double> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int max_overlap = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n && b[j] <= a[i]) {
            j++;
        }
        int current_count = (i + 1) - j;
        if (current_count > max_overlap) {
            max_overlap = current_count;
        }
    }

    cout << max_overlap << endl;

    return 0;
}