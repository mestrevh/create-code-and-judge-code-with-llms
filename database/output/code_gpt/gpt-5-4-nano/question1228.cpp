/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;

    vector<long long> a;
    long long x;
    bool neg = false, inNum = false;
    string num;
    for (size_t i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '-' || isdigit(static_cast<unsigned char>(c))) {
            num.push_back(c);
            inNum = true;
        } else {
            if (inNum) {
                a.push_back(stoll(num));
                num.clear();
                inNum = false;
            }
        }
    }
    if (inNum) a.push_back(stoll(num));

    long long sum = 0;
    long long cnt = 0;
    for (auto v : a) {
        if (v % 2 != 0) {
            sum += v;
            cnt++;
        }
    }

    double ans = (cnt == 0) ? 0.0 : (double)sum / (double)cnt;
    cout.setf(std::ios::fixed);
    cout << setprecision(2) << ans;
    return 0;
}