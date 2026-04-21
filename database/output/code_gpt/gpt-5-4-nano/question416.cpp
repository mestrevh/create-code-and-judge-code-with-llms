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
    
    auto convertBase = [&](long long x, int b) -> string {
        const string digits = "0123456789ABCDEF";
        if (x == 0) return "0";
        bool neg = x < 0;
        unsigned long long v = neg ? (unsigned long long)(-x) : (unsigned long long)x;
        stack<char> st;
        while (v > 0) {
            int r = (int)(v % b);
            st.push(digits[r]);
            v /= b;
        }
        string s;
        if (neg) s.push_back('-');
        while (!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }
        return s;
    };
    
    for (int i = 0; i < n; i++) {
        long long x;
        int b;
        cin >> x;
        cin >> b;
        cout << convertBase(x, b) << "\n";
    }
    return 0;
}