/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        string A;
        cin >> A;

        vector<char> st;
        st.reserve(A.size());

        auto is_open = [&](char c) {
            return c == '(' || c == '[' || c == '{';
        };
        auto match = [&](char open, char close) {
            return (open == '(' && close == ')') ||
                   (open == '[' && close == ']') ||
                   (open == '{' && close == '}');
        };

        bool ok = true;
        for (char c : A) {
            if (is_open(c)) {
                st.push_back(c);
            } else {
                if (st.empty() || !match(st.back(), c)) {
                    ok = false;
                    break;
                }
                st.pop_back();
            }
        }

        if (ok && !st.empty()) ok = false;
        cout << (ok ? 'S' : 'N') << "\n";
    }
    return 0;
}