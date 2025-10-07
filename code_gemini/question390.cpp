/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cmath>
#include <iomanip>
#include <cctype>

using namespace std;

const double PI = 3.141592653589793;

enum TokenType {
    NUMBER, VARIABLE, OPERATOR, FUNCTION, LPAREN, RPAREN
};

struct Token {
    TokenType type;
    string value;
};

map<string, int> precedence = {
    {"+", 2}, {"-", 2},
    {"*", 3}, {"/", 3},
    {"^", 4},
    {"#", 5} // Unary minus
};

map<string, char> associativity = {
    {"+", 'L'}, {"-", 'L'},
    {"*", 'L'}, {"/", 'L'},
    {"^", 'R'},
    {"#", 'R'}
};

vector<Token> tokenize(const string& expr) {
    vector<Token> tokens;
    bool expect_operand = true;

    for (size_t i = 0; i < expr.length(); ++i) {
        char c = expr[i];

        if (isspace(c)) {
            continue;
        }

        if (isdigit(c) || c == '.') {
            string num_str;
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                num_str += expr[i];
                i++;
            }
            i--;
            tokens.push_back({NUMBER, num_str});
            expect_operand = false;
        } else if (isalpha(c)) {
            string id_str;
            while (i < expr.length() && isalpha(expr[i])) {
                id_str += expr[i];
                i++;
            }
            i--;
            if (id_str == "X" || id_str == "Y" || id_str == "pi") {
                tokens.push_back({VARIABLE, id_str});
                expect_operand = false;
            } else {
                tokens.push_back({FUNCTION, id_str});
            }
        } else if (c == '(') {
            tokens.push_back({LPAREN, "("});
            expect_operand = true;
        } else if (c == ')') {
            tokens.push_back({RPAREN, ")"});
            expect_operand = false;
        } else {
            if (c == '-' && expect_operand) {
                tokens.push_back({OPERATOR, "#"});
            } else {
                tokens.push_back({OPERATOR, string(1, c)});
            }
            expect_operand = true;
        }
    }
    return tokens;
}

vector<Token> infix_to_rpn(const vector<Token>& tokens) {
    vector<Token> output_queue;
    stack<Token> operator_stack;

    for (const auto& token : tokens) {
        switch (token.type) {
            case NUMBER:
            case VARIABLE:
                output_queue.push_back(token);
                break;
            case FUNCTION:
                operator_stack.push(token);
                break;
            case OPERATOR:
                while (!operator_stack.empty()) {
                    Token top = operator_stack.top();
                    if (top.type != OPERATOR) break;

                    int p1 = precedence.at(token.value);
                    int p2 = precedence.at(top.value);
                    char a1 = associativity.at(token.value);

                    if ((a1 == 'L' && p1 <= p2) || (a1 == 'R' && p1 < p2)) {
                        output_queue.push_back(top);
                        operator_stack.pop();
                    } else {
                        break;
                    }
                }
                operator_stack.push(token);
                break;
            case LPAREN:
                operator_stack.push(token);
                break;
            case RPAREN:
                while (!operator_stack.empty() && operator_stack.top().type != LPAREN) {
                    output_queue.push_back(operator_stack.top());
                    operator_stack.pop();
                }
                if (!operator_stack.empty() && operator_stack.top().type == LPAREN) {
                    operator_stack.pop();
                }
                if (!operator_stack.empty() && operator_stack.top().type == FUNCTION) {
                    output_queue.push_back(operator_stack.top());
                    operator_stack.pop();
                }
                break;
        }
    }

    while (!operator_stack.empty()) {
        output_queue.push_back(operator_stack.top());
        operator_stack.pop();
    }

    return output_queue;
}

double evaluate_rpn(const vector<Token>& rpn, double x, double y) {
    stack<double> eval_stack;

    for (const auto& token : rpn) {
        if (token.type == NUMBER) {
            eval_stack.push(stod(token.value));
        } else if (token.type == VARIABLE) {
            if (token.value == "X") eval_stack.push(x);
            else if (token.value == "Y") eval_stack.push(y);
            else if (token.value == "pi") eval_stack.push(PI);
        } else if (token.type == OPERATOR) {
            if (token.value == "#") {
                double val = eval_stack.top(); eval_stack.pop();
                eval_stack.push(-val);
            } else {
                double b = eval_stack.top(); eval_stack.pop();
                double a = eval_stack.top(); eval_stack.pop();
                if (token.value == "+") eval_stack.push(a + b);
                else if (token.value == "-") eval_stack.push(a - b);
                else if (token.value == "*") eval_stack.push(a * b);
                else if (token.value == "/") eval_stack.push(a / b);
                else if (token.value == "^") eval_stack.push(pow(a, b));
            }
        } else if (token.type == FUNCTION) {
            double arg = eval_stack.top(); eval_stack.pop();
            if (token.value == "sin") eval_stack.push(sin(arg));
            else if (token.value == "cos") eval_stack.push(cos(arg));
            else if (token.value == "tan") eval_stack.push(tan(arg));
            else if (token.value == "asin") eval_stack.push(asin(arg));
            else if (token.value == "acos") eval_stack.push(acos(arg));
            else if (token.value == "atan") eval_stack.push(atan(arg));
            else if (token.value == "exp") eval_stack.push(exp(arg));
            else if (token.value == "log") eval_stack.push(log(arg));
            else if (token.value == "log10") eval_stack.push(log10(arg));
            else if (token.value == "sqrt") eval_stack.push(sqrt(arg));
            else if (token.value == "abs") eval_stack.push(abs(arg));
        }
    }
    return eval_stack.top();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(2);

    string expr_str;
    getline(cin, expr_str);

    double x0, y0, xf;
    int n;
    cin >> x0 >> y0 >> n >> xf;

    vector<Token> tokens = tokenize(expr_str);
    vector<Token> rpn = infix_to_rpn(tokens);

    double h = (xf - x0) / static_cast<double>(n);
    double current_x = x0;
    double current_y = y0;

    cout << current_x << " " << current_y << endl;

    for (int i = 0; i < n; ++i) {
        double slope = evaluate_rpn(rpn, current_x, current_y);
        current_y += h * slope;
        current_x = x0 + (i + 1) * h;
        cout << current_x << " " << current_y << endl;
    }

    return 0;
}
