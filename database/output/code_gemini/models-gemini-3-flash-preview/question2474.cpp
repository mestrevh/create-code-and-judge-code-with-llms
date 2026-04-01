/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    if (!(cin >> s1 >> s2)) return 0;

    bool neg = false;
    if (!s1.empty() && s1[0] == '-') {
        neg = !neg;
        s1 = s1.substr(1);
    }
    if (!s2.empty() && s2[0] == '-') {
        neg = !neg;
        s2 = s2.substr(1);
    }

    auto is_zero = [](const string& s) {
        if (s.empty()) return true;
        for (char c : s) {
            if (c != '0') return false;
        }
        return true;
    };

    if (is_zero(s1) || is_zero(s2)) {
        cout << "0" << endl;
        return 0;
    }

    int n = s1.size();
    int m = s2.size();
    vector<long long> res(n + m, 0);

    for (int i = n - 1; i >= 0; --i) {
        int d1 = s1[i] - '0';
        if (d1 == 0) continue;
        for (int j = m - 1; j >= 0; --j) {
            int d2 = s2[j] - '0';
            res[i + j + 1] += (long long)d1 * d2;
            if (res[i + j + 1] >= 10) {
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }
    }

    for (int i = n + m - 1; i > 0; --i) {
        if (res[i] >= 10) {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }
    }

    int idx = 0;
    while (idx < n + m && res[idx] == 0) {
        idx++;
    }

    if (idx == n + m) {
        cout << "0" << endl;
    } else {
        if (neg) cout << '-';
        while (idx < n + m) {
            cout << res[idx++];
        }
        cout << endl;
    }

    return 0;
}