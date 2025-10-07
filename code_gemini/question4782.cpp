/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    while (n--) {
        std::string s;
        std::cin >> s;
        std::stack<char> st;
        bool isValid = true;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) {
                    isValid = false;
                    break;
                }
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    isValid = false;
                    break;
                }
            }
        }

        if (!st.empty()) {
            isValid = false;
        }

        if (isValid) {
            std::cout << "True\n";
        } else {
            std::cout << "False\n";
        }
    }

    return 0;
}
