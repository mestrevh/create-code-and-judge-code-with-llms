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

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    long long total_time = 0;
    for (int i = 0; i < n - 1; ++i) {
        int diff = t[i + 1] - t[i];
        if (diff < 10) {
            total_time += diff;
        } else {
            total_time += 10;
        }
    }

    total_time += 10;

    cout << total_time << endl;

    return 0;
}