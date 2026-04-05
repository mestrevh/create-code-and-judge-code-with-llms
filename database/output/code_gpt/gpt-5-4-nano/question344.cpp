/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double x;
    if (!(cin >> x)) return 0;

    bool neg = x < 0;
    if (neg) x = -x;

    long double scaled = x;
    long long denom = 1, num = 0;

    string s;
    {
        ostringstream oss;
        oss.setf(std::ios::fixed);
        oss << setprecision(20) << (double)x;
        s = oss.str();
        s.erase(s.find_last_not_of('0') + 1);
        if (!s.empty() && s.back() == '.') s.pop_back();
    }

    size_t pos = s.find('.');
    if (pos == string::npos) {
        num = stoll(s);
        denom = 1;
    } else {
        string a = s.substr(0, pos);
        string b = s.substr(pos + 1);
        if (b.empty()) {
            num = stoll(a);
            denom = 1;
        } else {
            int k = (int)b.size();
            string combined = a + b;
            num = stoll(combined);
            denom = 1;
            for (int i = 0; i < k; i++) denom *= 10;
        }
    }

    long long g = std::gcd(llabs(num), denom);
    num /= g;
    denom /= g;

    if (neg) num = -num;

    cout << num << "/" << denom;
    return 0;
}