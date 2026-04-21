/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <cctype>

using namespace std;

typedef long long ll;

bool is_number(const string& s) {
    if (s.empty()) return false;
    if (s == "+" || s == "-" || s == "*") return false;
    size_t start = 0;
    if ((s[0] == '-' || s[0] == '+') && s.size() > 1) start = 1;
    for (size_t i = start; i < s.size(); ++i) {
        if (!isdigit(static_cast<unsigned char>(s[i]))) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string token;
    map<string, int> varValues;
    vector<string> order;

    while (cin >> token && token != "EOF") {
        if (token == "=") {
            string varName;
            if (!(cin >> varName)) break;
            
            while (!varName.empty() && varName.back() == ';') {
                varName.pop_back();
            }

            stack<ll> evalStack;
            string expr;
            bool assignmentComplete = false;
            
            while (!assignmentComplete && cin >> expr) {
                if (expr == "EOF") {
                    token = "EOF";
                    break;
                }

                bool semi = false;
                while (!expr.empty() && expr.back() == ';') {
                    semi = true;
                    expr.pop_back();
                }

                if (!expr.empty()) {
                    if (expr == "+") {
                        if (evalStack.size() >= 2) {
                            ll v2 = evalStack.top(); evalStack.pop();
                            ll v1 = evalStack.top(); evalStack.pop();
                            evalStack.push(v1 + v2);
                        }
                    } else if (expr == "-") {
                        if (evalStack.size() >= 2) {
                            ll v2 = evalStack.top(); evalStack.pop();
                            ll v1 = evalStack.top(); evalStack.pop();
                            evalStack.push(v1 - v2);
                        }
                    } else if (expr == "*") {
                        if (evalStack.size() >= 2) {
                            ll v2 = evalStack.top(); evalStack.pop();
                            ll v1 = evalStack.top(); evalStack.pop();
                            evalStack.push(v1 * v2);
                        }
                    } else if (is_number(expr)) {
                        evalStack.push(stoll(expr));
                    } else {
                        if (varValues.count(expr)) {
                            evalStack.push(varValues[expr]);
                        }
                    }
                }

                if (semi) {
                    assignmentComplete = true;
                }
            }

            if (!evalStack.empty()) {
                if (varValues.find(varName) == varValues.end()) {
                    order.push_back(varName);
                }
                varValues[varName] = static_cast<int>(evalStack.top());
            }
            
            if (token == "EOF") break;
        }
    }

    for (const string& name : order) {
        cout << name << " = " << varValues[name] << "\n";
    }

    return 0;
}