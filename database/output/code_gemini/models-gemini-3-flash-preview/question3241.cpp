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
    int initial_ones = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            initial_ones++;
        }
    }

    int max_gain = -1e9;
    int current_gain = -1e9;

    for (int i = 0; i < n; ++i) {
        int val = (a[i] == 0) ? 1 : -1;
        current_gain = max(val, current_gain + val);
        max_gain = max(max_gain, current_gain);
    }

    cout << initial_ones + max_gain << endl;

    return 0;
}