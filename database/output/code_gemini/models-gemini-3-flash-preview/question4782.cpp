/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        string s;
        if (!(cin >> s)) break;

        stack<char> st;
        bool valid = true;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) {
                    valid = false;
                    break;
                }
                char top = st.top();
                if ((c == ')' && top == '(') || 
                    (c == ']' && top == '[') || 
                    (c == '}' && top == '{')) {
                    st.pop();
                } else {
                    valid = false;
                    break;
                }
            }
        }

        if (valid && st.empty()) {
            cout << "True\n";
        } else {
            cout << "False\n";
        }
    }

    return 0;
}