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

    long double mm = x * 25.4L;

    cout << fixed << setprecision(10) << (double)x;
    string s1 = to_string((double)x);
    if (s1.find('.') != string::npos) {
        while (!s1.empty() && s1.back() == '0') s1.pop_back();
        if (!s1.empty() && s1.back() == '.') s1.pop_back();
    }
    cout.flush();

    auto to_trim = [](long double v) -> string {
        ostringstream oss;
        oss << fixed << setprecision(10) << (double)v;
        string s = oss.str();
        if (s.find('.') != string::npos) {
            while (!s.empty() && s.back() == '0') s.pop_back();
            if (!s.empty() && s.back() == '.') s.pop_back();
        }
        return s;
    };

    string a = to_trim(x);
    string b = to_trim(mm);

    cout.clear();
    cout.str("");
    cout << a << " polegada(s) eh o mesmo que " << b << " mm";
    return 0;
}