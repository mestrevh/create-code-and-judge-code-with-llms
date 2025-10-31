/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 0;
    if (op == '*' || op == '/') return 1;
    if (op == '^') return 2;
    return -1;
}

string infixToPostfix(const string& expression) {
    stack<char> operators;
    string output;

    for (char ch : expression) {
        if (isalpha(ch)) {
            output += ch;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output += operators.top();
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                output += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        output += operators.top();
        operators.pop();
    }

    return output;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    vector<string> expressions(N);
    
    for (int i = 0; i < N; ++i) {
        getline(cin, expressions[i]);
    }

    for (const string& expr : expressions) {
        cout << infixToPostfix(expr) << endl;
    }

    return 0;
}
