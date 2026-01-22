/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>

void solve() {
    std::string line;
    std::getline(std::cin, line);

    std::stack<char> st;
    bool is_balanced = true;

    for (char c : line) {
        if (c == '(' || c == '[') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                is_balanced = false;
                break;
            }
            st.pop();
        } else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                is_balanced = false;
                break;
            }
            st.pop();
        }
    }

    if (!st.empty()) {
        is_balanced = false;
    }

    if (is_balanced) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore(); 

    while (n--) {
        solve();
    }

    return 0;
}
