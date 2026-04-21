/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int getPrecedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isLeftAssociative(char c) {
    if (c == '^') return false;
    return true;
}

void processExpression() {
    string expr;
    if (!(cin >> expr)) return;
    
    string output = "";
    stack<char> s;
    
    for (char c : expr) {
        if (c >= 'a' && c <= 'z') {
            output += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                output += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        } else {
            int p = getPrecedence(c);
            while (!s.empty() && s.top() != '(') {
                int topP = getPrecedence(s.top());
                if (topP > p || (topP == p && isLeftAssociative(c))) {
                    output += s.top();
                    s.pop();
                } else {
                    break;
                }
            }
            s.push(c);
        }
    }
    
    while (!s.empty()) {
        if (s.top() != '(') output += s.top();
        s.pop();
    }
    
    cout << output << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        processExpression();
    }
    
    return 0;
}