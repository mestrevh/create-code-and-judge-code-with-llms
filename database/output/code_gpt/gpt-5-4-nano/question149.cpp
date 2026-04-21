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
        cin >> ws;
        getline(cin, s);

        stack<char> st;
        string out;
        auto prec = [&](char op) -> int {
            if (op == '+' || op == '-') return 0;
            if (op == '*' || op == '/') return 1;
            if (op == '^') return 2;
            return -1;
        };

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                out.push_back(c);
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    out.push_back(st.top());
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') st.pop();
            } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                while (!st.empty()) {
                    char top = st.top();
                    if (top == '(') break;
                    int p1 = prec(c), p2 = prec(top);
                    bool rightAssoc = (c == '^');
                    if ((!rightAssoc && p1 <= p2) || (rightAssoc && p1 < p2)) {
                        out.push_back(top);
                        st.pop();
                    } else break;
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            if (st.top() != '(') out.push_back(st.top());
            st.pop();
        }

        cout << out;
        if (N) cout << "\n";
    }
    return 0;
}