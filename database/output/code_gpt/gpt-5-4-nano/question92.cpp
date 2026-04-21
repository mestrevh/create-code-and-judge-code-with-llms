/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string reverseDigits(const string& s) {
    string t = s;
    reverse(t.begin(), t.end());
    return t;
}

static string trimLeadingZeros(const string& s) {
    int i = 0;
    while (i + 1 < (int)s.size() && s[i] == '0') i++;
    return s.substr(i);
}

static bool isPalindrome(const string& s) {
    for (int i = 0, j = (int)s.size() - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}

static string addBig(const string& a, const string& b) {
    int i = (int)a.size() - 1, j = (int)b.size() - 1, carry = 0;
    string res;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res.push_back(char('0' + (sum % 10)));
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return trimLeadingZeros(res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    for (int tc = 0; tc < N; tc++) {
        string x;
        cin >> x;
        x = trimLeadingZeros(x);
        if (x.empty()) x = "0";

        string cur = x;
        int it = 0;
        while (!isPalindrome(cur)) {
            string rev = reverseDigits(cur);
            rev = trimLeadingZeros(rev);
            cur = addBig(cur, rev);
            it++;
            if (it >= 1000) break;
        }

        cout << it << ' ' << cur << "\n";
    }
    return 0;
}