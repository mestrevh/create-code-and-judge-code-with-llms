/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Token {
    enum Type { VAR, OP, LP, RP } type;
    char v;
    Token(Type t=VAR, char c=0): type(t), v(c) {}
};

static int prec(char op) {
    if(op=='^') return 3;
    if(op=='*' || op=='/') return 2;
    if(op=='+' || op=='-') return 1;
    return 0;
}

static bool rightAssociative(char op) {
    return op=='^';
}

static bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

static vector<Token> tokenize(const string& s) {
    vector<Token> tok;
    for(char c: s) {
        if(c>='a' && c<='z') tok.emplace_back(Token::VAR, c);
        else if(c=='(') tok.emplace_back(Token::LP, c);
        else if(c==')') tok.emplace_back(Token::RP, c);
        else if(isOperator(c)) tok.emplace_back(Token::OP, c);
    }
    return tok;
}

static string toRPN(const string& s) {
    auto tok = tokenize(s);
    vector<char> st;
    string out;
    for(const auto& t: tok) {
        if(t.type==Token::VAR) {
            out.push_back(t.v);
        } else if(t.type==Token::OP) {
            char op = t.v;
            while(!st.empty()) {
                char top = st.back();
                if(top=='(') break;
                int pTop = prec(top);
                int pOp = prec(op);
                if(pTop > pOp || (pTop == pOp && !rightAssociative(op))) {
                    out.push_back(top);
                    st.pop_back();
                } else break;
            }
            st.push_back(op);
        } else if(t.type==Token::LP) {
            st.push_back('(');
        } else if(t.type==Token::RP) {
            while(!st.empty() && st.back()!='(') {
                out.push_back(st.back());
                st.pop_back();
            }
            if(!st.empty() && st.back()=='(') st.pop_back();
        }
    }
    while(!st.empty()) {
        if(st.back()!='(') out.push_back(st.back());
        st.pop_back();
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    string line;
    for(int i=0;i<t;i++) {
        cin >> line;
        cout << toRPN(line) << "\n";
    }
    return 0;
}