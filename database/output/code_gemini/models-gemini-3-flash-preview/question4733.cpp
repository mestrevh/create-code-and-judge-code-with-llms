/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <limits>

using namespace std;

bool is_op(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool is_operand(char c) {
    return (c >= 'a' && c <= 'z');
}

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isRightAssoc(char c) {
    return c == '^';
}

bool isValid(const string& s) {
    int balance = 0;
    char prev = '\0';
    bool hasContent = false;
    for (char c : s) {
        if (isspace(c)) continue;
        hasContent = true;
        if (c == '(') {
            if (prev != '\0' && !is_op(prev) && prev != '(') return false;
            balance++;
        } else if (c == ')') {
            if (balance <= 0 || is_op(prev) || prev == '(') return false;
            balance--;
        } else if (is_op(c)) {
            if (prev == '\0' || prev == '(' || is_op(prev)) return false;
        } else if (is_operand(c)) {
            if (prev != '\0' && !is_op(prev) && prev != '(') return false;
        } else {
            return false;
        }
        prev = c;
    }
    return hasContent && balance == 0 && (is_operand(prev) || prev == ')');
}

string toRPN(const string& s) {
    string output = "";
    stack<char> ops;
    for (char c : s) {
        if (isspace(c)) continue;
        if (is_operand(c)) {
            output += c;
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                output += ops.top();
                ops.pop();
            }
            if (!ops.empty()) ops.pop();
        } else if (is_op(c)) {
            while (!ops.empty() && ops.top() != '(') {
                int p1 = prec(c);
                int p2 = prec(ops.top());
                if ((!isRightAssoc(c) && p1 <= p2) || (isRightAssoc(c) && p1 < p2)) {
                    output += ops.top();
                    ops.pop();
                } else {
                    break;
                }
            }
            ops.push(c);
        }
    }
    while (!ops.empty()) {
        output += ops.top();
        ops.pop();
    }
    return output;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    string line;
    getline(cin, line);
    while (t > 0) {
        if (!getline(cin, line)) break;
        size_t first = line.find_first_not_of(" \t\n\r");
        if (first == string::npos) continue;
        size_t last = line.find_last_not_of(" \t\n\r");
        string trimmed = line.substr(first, (last - first + 1));
        if (isValid(trimmed)) {
            cout << toRPN(trimmed) << "\n";
        } else {
            cout << "The expression is not valid\n";
        }
        t--;
    }
    return 0;
}