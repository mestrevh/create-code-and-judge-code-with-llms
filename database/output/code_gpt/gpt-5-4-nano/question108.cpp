/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> freq(10, 0);
    for (double x : a) {
        if (x < 0.0) continue;
        if (x > 10.0) continue;
        int idx;
        if (x == 10.0) idx = 9;
        else idx = (int)floor(x);
        if (idx < 0) idx = 0;
        if (idx > 9) idx = 9;
        freq[idx]++;
    }

    int maxF = 0;
    for (int f : freq) maxF = max(maxF, f);

    auto segmentChar = [&](int idx) -> char {
        if (idx == 0) return '^';
        if (idx == 9) return '>';
        return '|';
    };

    for (int row = maxF; row >= 1; row--) {
        for (int i = 0; i < 10; i++) {
            if (freq[i] >= row) cout << '*';
            else cout << ' ';
        }
        cout << "\n";
    }

    cout << "+";
    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < freq[i] > 0 ? 1 : 1; k++) {}
        if (i == 9) {
            for (int k = 0; k < freq[i]; k++) cout << '-';
        } else {
            for (int k = 0; k < freq[i]; k++) cout << '-';
        }
    }
    cout << ">\n";

    return 0;
}