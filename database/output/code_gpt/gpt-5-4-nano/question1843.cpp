/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, line;
    if (!getline(cin, line)) return 0;
    s = line;

    vector<long long> a;
    long long sign = 1, val = 0;
    bool inNum = false;

    for (char c : s) {
        if ((c >= '0' && c <= '9') || c == '-') {
            if (!inNum && c == '-') {
                sign = -1;
                inNum = true;
                val = 0;
            } else if (isdigit((unsigned char)c)) {
                if (!inNum) {
                    inNum = true;
                    sign = 1;
                    val = 0;
                }
                val = val * 10 + (c - '0');
            }
        } else {
            if (inNum) {
                a.push_back(sign * val);
                inNum = false;
                sign = 1;
                val = 0;
            }
        }
    }
    if (inNum) a.push_back(sign * val);

    long long mn = a[0], mx = a[0];
    long double sum = 0;
    for (auto x : a) {
        mn = min(mn, x);
        mx = max(mx, x);
        sum += (long double)x;
    }
    long double avg = sum / (long double)a.size();

    cout << "Maior: " << mx << "\n";
    cout << "Menor: " << mn << "\n";
    cout << fixed << setprecision(2);
    cout << "Media: " << (double)avg << "\n";
    return 0;
}