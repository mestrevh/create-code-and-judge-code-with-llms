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
    if (!(cin >> s)) return 0;

    size_t pos = s.find_first_of('.');
    string intPart = (pos == string::npos) ? s : s.substr(0, pos);

    bool neg = false;
    if (!intPart.empty() && intPart[0] == '-') {
        neg = true;
        intPart = intPart.substr(1);
    }

    if (intPart.empty()) intPart = "0";

    auto trim = [](string t) {
        int i = 0;
        while (i < (int)t.size() && t[i] == '0') i++;
        if (i == (int)t.size()) return string("0");
        return t.substr(i);
    };

    intPart = trim(intPart);

    if (intPart == "0") {
        cout << 0 << "\n";
        return 0;
    }

    int len = (int)intPart.size();
    long long ans = len - 1;
    if (neg) ans = ans;
    cout << ans << "\n";
    return 0;
}