/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    while (N--) {
        string s;
        cin >> s;
        stack<char> st;
        bool ok = true;

        auto match = [&](char open, char close) {
            return (open == '(' && close == ')') ||
                   (open == '[' && close == ']') ||
                   (open == '{' && close == '}');
        };

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty() || !match(st.top(), c)) {
                    ok = false;
                    break;
                }
                st.pop();
            }
        }

        if (!st.empty()) ok = false;
        cout << (ok ? "True" : "False") << "\n";
    }
    return 0;
}