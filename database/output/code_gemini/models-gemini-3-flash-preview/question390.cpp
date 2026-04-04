/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>

using namespace std;

const double PI_VAL = 3.141592653589793;

enum TokenType { VAR, NUM, OP, FUNC, LPAR, RPAR };

struct Token {
    TokenType type;
    string val;
    double num;
    int prec;
};

vector<Token> tokenize(string s) {
    vector<Token> tokens;
    for (int i = 0; i < (int)s.length(); ++i) {
        if (isspace(s[i])) continue;
        if (isdigit(s[i]) || s[i] == '.') {
            string n;
            while (i < (int)s.length() && (isdigit(s[i]) || s[i] == '.')) n += s[i++];
            tokens.push_back({NUM, n, stod(n), 0});
            i--;
        } else if (isalpha(s[i])) {
            string name;
            while (i < (int)s.length() && (isalnum(s[i]))) name += s[i++];
            if (name == "X" || name == "Y") {
                tokens.push_back({VAR, name, 0, 0});
            } else if (name == "pi") {
                tokens.push_back({NUM, name, PI_VAL, 0});
            } else {
                tokens.push_back({FUNC, name, 0, 0});
            }
            i--;
        } else if (s[i] == '(') {
            tokens.push_back({LPAR, "(", 0, 0});
        } else if (s[i] == ')') {
            tokens.push_back({RPAR, ")", 0, 0});
        } else {
            string op(1, s[i]);
            int prec = 0;
            if (s[i] == '+' || s[i] == '-') prec = 1;
            else if (s[i] == '*' || s[i] == '/') prec = 2;
            else if (s[i] == '^') prec = 4;
            tokens.push_back({OP, op, 0, prec});
        }
    }
    return tokens;
}

vector<Token> shuntingYard(const vector<Token>& tokens) {
    vector<Token> rpn;
    stack<Token> ops;
    for (int i = 0; i < (int)tokens.size(); ++i) {
        const auto& t = tokens[i];
        if (t.type == NUM || t.type == VAR) {
            rpn.push_back(t);
        } else if (t.type == FUNC) {
            ops.push(t);
        } else if (t.type == OP) {
            Token actualT = t;
            bool isUnary = false;
            if (t.val == "+" || t.val == "-") {
                if (i == 0 || tokens[i - 1].type == OP || tokens[i - 1].type == LPAR) {
                    actualT.val = (t.val == "-" ? "u-" : "u+");
                    actualT.prec = 3;
                    isUnary = true;
                }
            }
            while (!ops.empty() && ops.top().type != LPAR) {
                if (actualT.prec < ops.top().prec || (actualT.prec == ops.top().prec && !isUnary)) {
                    rpn.push_back(ops.top());
                    ops.pop();
                } else {
                    break;
                }
            }
            ops.push(actualT);
        } else if (t.type == LPAR) {
            ops.push(t);
        } else if (t.type == RPAR) {
            while (!ops.empty() && ops.top().type != LPAR) {
                rpn.push_back(ops.top());
                ops.pop();
            }
            if (!ops.empty()) ops.pop();
            if (!ops.empty() && ops.top().type == FUNC) {
                rpn.push_back(ops.top());
                ops.pop();
            }
        }
    }
    while (!ops.empty()) {
        rpn.push_back(ops.top());
        ops.pop();
    }
    return rpn;
}

double evaluate(const vector<Token>& rpn, double X, double Y) {
    stack<double> s;
    for (const auto& t : rpn) {
        if (t.type == NUM) s.push(t.num);
        else if (t.type == VAR) {
            if (t.val == "X") s.push(X);
            else if (t.val == "Y") s.push(Y);
        } else if (t.type == OP) {
            if (t.val == "u-") {
                double a = s.top(); s.pop();
                s.push(-a);
            } else if (t.val == "u+") {
                // Unary plus does nothing
            } else {
                double b = s.top(); s.pop();
                double a = s.top(); s.pop();
                if (t.val == "+") s.push(a + b);
                else if (t.val == "-") s.push(a - b);
                else if (t.val == "*") s.push(a * b);
                else if (t.val == "/") s.push(a / b);
                else if (t.val == "^") s.push(pow(a, b));
            }
        } else if (t.type == FUNC) {
            double a = s.top(); s.pop();
            if (t.val == "sin") s.push(sin(a));
            else if (t.val == "cos") s.push(cos(a));
            else if (t.val == "tan") s.push(tan(a));
            else if (t.val == "exp") s.push(exp(a));
            else if (t.val == "log") s.push(log(a));
            else if (t.val == "log10") s.push(log10(a));
            else if (t.val == "sqrt") s.push(sqrt(a));
            else if (t.val == "abs") s.push(abs(a));
            else if (t.val == "asin") s.push(asin(a));
            else if (t.val == "acos") s.push(acos(a));
            else if (t.val == "atan") s.push(atan(a));
            else s.push(0); 
        }
    }
    return s.empty() ? 0 : s.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string expr;
    if (!getline(cin, expr)) return 0;
    while (!expr.empty() && (expr.back() == '\r' || expr.back() == '\n')) expr.pop_back();
    
    double x0, y0, xf;
    int n;
    if (!(cin >> x0 >> y0 >> n >> xf)) return 0;

    vector<Token> tokens = tokenize(expr);
    vector<Token> rpn = shuntingYard(tokens);

    double h = (xf - x0) / (double)n;
    double curX = x0;
    double curY = y0;

    for (int i = 0; i <= n; ++i) {
        cout << fixed << setprecision(2) << (abs(curX) < 1e-9 ? 0.00 : curX) << " " << curY << "\n";
        if (i < n) {
            double slope = evaluate(rpn, curX, curY);
            curY = curY + h * slope;
            curX = x0 + (double)(i + 1) * h;
        }
    }

    return 0;
}