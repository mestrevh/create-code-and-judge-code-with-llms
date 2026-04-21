/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Token {
    enum Type { OPERAND, OP, LPAREN, RPAREN } type;
    char val;
};

static bool isOperand(char c) {
    return c >= 'a' && c <= 'z';
}

static bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    string line;
    getline(cin, line);

    while (t--) {
        string s;
        getline(cin, s);
        while (s.size() == 0 && !cin.eof()) getline(cin, s);

        bool valid = true;

        vector<char> opstack;
        string output;
        enum Expect { EXPECT_OPERAND_OR_LPAREN, EXPECT_OPERATOR_OR_RPAREN, EXPECT_END };
        Expect expect = EXPECT_OPERAND_OR_LPAREN;

        auto prec = [&](char op)->int{
            if(op=='^') return 4;
            if(op=='*' || op=='/') return 3;
            if(op=='+' || op=='-') return 2;
            return 0;
        };
        auto rightAssoc = [&](char op)->bool{
            return op=='^';
        };

        for (size_t i = 0; i < s.size() && valid; i++) {
            char c = s[i];
            if (isspace((unsigned char)c)) continue;

            if (isOperand(c)) {
                if (expect != EXPECT_OPERAND_OR_LPAREN) {
                    valid = false; break;
                }
                output.push_back(c);
                expect = EXPECT_OPERATOR_OR_RPAREN;
            } else if (c == '(') {
                if (expect != EXPECT_OPERAND_OR_LPAREN) {
                    valid = false; break;
                }
                opstack.push_back(c);
            } else if (c == ')') {
                if (expect != EXPECT_OPERATOR_OR_RPAREN) {
                    valid = false; break;
                }
                bool found = false;
                while (!opstack.empty()) {
                    char top = opstack.back();
                    opstack.pop_back();
                    if (top == '(') { found = true; break; }
                    if (isOperator(top)) output.push_back(top);
                    else { valid = false; break; }
                }
                if (!found) valid = false;
                if (!valid) break;
                expect = EXPECT_OPERATOR_OR_RPAREN;
            } else if (isOperator(c)) {
                if (expect != EXPECT_OPERATOR_OR_RPAREN) {
                    valid = false; break;
                }
                char op = c;
                while (!opstack.empty() && isOperator(opstack.back())) {
                    char top = opstack.back();
                    int p1 = prec(op), p2 = prec(top);
                    if (p2 > p1 || (p2 == p1 && !rightAssoc(op))) {
                        opstack.pop_back();
                        output.push_back(top);
                    } else break;
                }
                opstack.push_back(op);
                expect = EXPECT_OPERAND_OR_LPAREN;
            } else {
                valid = false;
                break;
            }
        }

        if (valid) {
            if (expect != EXPECT_OPERATOR_OR_RPAREN) valid = false;
        }

        if (valid) {
            while (!opstack.empty() && valid) {
                char top = opstack.back();
                opstack.pop_back();
                if (top == '(' || top == ')') { valid = false; break; }
                if (isOperator(top)) output.push_back(top);
                else { valid = false; break; }
            }
        }

        if (!valid) {
            cout << "The expression is not valid\n";
        } else {
            cout << output << "\n";
        }
    }
    return 0;
}