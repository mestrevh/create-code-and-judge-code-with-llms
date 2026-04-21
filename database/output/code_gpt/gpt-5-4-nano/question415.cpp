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
    string s;
    getline(cin, s);

    while (n--) {
        getline(cin, s);
        stack<char> st;
        bool ok = true;

        for (char c : s) {
            if (c == ' ' || c == '\t' || c == '\r' || c == '\n') continue;
            if (c == '(' || c == '[') {
                st.push(c);
            } else if (c == ')' || c == ']') {
                if (st.empty()) { ok = false; break; }
                char top = st.top();
                if ((c == ')' && top != '(') || (c == ']' && top != '[')) { ok = false; break; }
                st.pop();
            }
        }

        if (!ok || !st.empty()) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}