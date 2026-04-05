/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

string stripLeadingZeros(const string& s) {
    int i = 0;
    while (i + 1 < (int)s.size() && s[i] == '0') i++;
    return s.substr(i);
}

string addBigInt(const string& a, const string& b) {
    int i = (int)a.size() - 1, j = (int)b.size() - 1;
    int carry = 0;
    string res;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res.push_back(char('0' + (sum % 10)));
        carry = sum / 10;
    }
    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

string mulBigInt(const string& a, const string& b) {
    a = stripLeadingZeros(a);
    b = stripLeadingZeros(b);
    if (a == "0" || b == "0") return "0";
    int n = (int)a.size(), m = (int)b.size();
    vector<long long> prod(n + m, 0);
    for (int i = n - 1; i >= 0; --i) {
        int da = a[i] - '0';
        for (int j = m - 1; j >= 0; --j) {
            int db = b[j] - '0';
            prod[i + j + 1] += 1LL * da * db;
        }
    }
    for (int k = n + m - 1; k > 0; --k) {
        if (prod[k] >= 10) {
            long long carry = prod[k] / 10;
            prod[k] %= 10;
            prod[k - 1] += carry;
        }
    }
    int start = 0;
    while (start + 1 < (int)prod.size() && prod[start] == 0) start++;
    string res;
    res.reserve((int)prod.size() - start);
    for (int i = start; i < (int)prod.size(); ++i) res.push_back(char('0' + prod[i]));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    if (!(cin >> a >> b)) return 0;

    a = stripLeadingZeros(a);
    b = stripLeadingZeros(b);

    cout << addBigInt(a, b) << "\n";
    cout << mulBigInt(a, b) << "\n";
    return 0;
}