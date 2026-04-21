/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string trim(const string& s){
    size_t a = 0, b = s.size();
    while(a < b && isspace((unsigned char)s[a])) a++;
    while(b > a && isspace((unsigned char)s[b-1])) b--;
    return s.substr(a, b-a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string eqLine;
    if(!std::getline(cin, eqLine)) return 0;
    eqLine = trim(eqLine);

    long double X0, Y0, Xf;
    long long n;
    if(!(cin >> X0)) return 0;
    if(!(cin >> Y0)) return 0;
    if(!(cin >> n)) return 0;
    if(!(cin >> Xf)) return 0;

    long double h = (Xf - X0) / (long double)n;

    string expr = eqLine;
    size_t pos = 0;

    struct Parser {
        const string& s;
        size_t& pos;
        Parser(const string& ss, size_t& p) : s(ss), pos(p) {}

        void skipSpaces(){
            while(pos < s.size() && isspace((unsigned char)s[pos])) pos++;
        }

        bool matchChar(char c){
            skipSpaces();
            if(pos < s.size() && s[pos] == c){
                pos++;
                return true;
            }
            return false;
        }

        string parseIdentifier(){
            skipSpaces();
            size_t start = pos;
            while(pos < s.size() && (isalpha((unsigned char)s[pos]) || s[pos]=='_')){
                pos++;
            }
            return s.substr(start, pos-start);
        }

        long double parseNumber(){
            skipSpaces();
            size_t start = pos;
            bool hasDigit = false;
            while(pos < s.size() && (isdigit((unsigned char)s[pos]) || s[pos]=='.')){
                hasDigit = true;
                pos++;
            }
            if(pos < s.size() && (s[pos]=='e' || s[pos]=='E')){
                size_t save = pos;
                pos++;
                if(pos < s.size() && (s[pos]=='+' || s[pos]=='-')) pos++;
                bool hasExp = false;
                while(pos < s.size() && isdigit((unsigned char)s[pos])){
                    hasExp = true;
                    pos++;
                }
                if(!hasDigit || !hasExp){
                    pos = save;
                }
            }
            string t = s.substr(start, pos-start);
            if(t.empty()) return 0.0L;
            return stold(t);
        }

        long double parsePrimary(long double X, long double Y){
            skipSpaces();
            if(matchChar('(')){
                long double v = parseExpression(X,Y);
                matchChar(')');
                return v;
            }

            skipSpaces();
            char c = (pos < s.size() ? s[pos] : '\0');

            if(c=='+' || c=='-' ){
                bool neg = false;
                if(matchChar('-')) neg = true;
                else matchChar('+');
                long double v = parsePrimary(X,Y);
                return neg ? -v : v;
            }

            if(pos < s.size() && (isdigit((unsigned char)s[pos]) || s[pos]=='.')){
                long double v = parseNumber();
                return v;
            }

            if(pos < s.size() && isalpha((unsigned char)s[pos])){
                string id = parseIdentifier();
                if(id == "X") return X;
                if(id == "Y") return Y;
                if(id == "pi") return 3.141592653589793L;
                if(matchChar('(')){
                    long double arg = parseExpression(X,Y);
                    matchChar(')');
                    if(id == "sin") return sinl(arg);
                    if(id == "cos") return cosl(arg);
                    if(id == "tan") return tanl(arg);
                    if(id == "exp") return expl(arg);
                    if(id == "log") return logl(arg);
                    if(id == "sqrt") return sqrtl(arg);
                    if(id == "asin") return asinl(arg);
                    if(id == "acos") return acosl(arg);
                    if(id == "atan") return atanl(arg);
                    if(id == "sinh") return sinhl(arg);
                    if(id == "cosh") return coshl(arg);
                    if(id == "tanh") return tanhl(arg);
                    return 0.0L;
                } else {
                    return 0.0L;
                }
            }

            return 0.0L;
        }

        long double parsePower(long double X, long double Y){
            long double left = parsePrimary(X,Y);
            skipSpaces();
            if(pos < s.size() && s[pos]=='^'){
                pos++;
                long double right = parsePower(X,Y);
                return powl(left, right);
            }
            return left;
        }

        long double parseTerm(long double X, long double Y){
            long double v = parsePower(X,Y);
            while(true){
                skipSpaces();
                if(pos >= s.size()) break;
                char op = s[pos];
                if(op=='*' || op=='/'){
                    pos++;
                    long double rhs = parsePower(X,Y);
                    if(op=='*') v *= rhs;
                    else v /= rhs;
                } else break;
            }
            return v;
        }

        long double parseExpression(long double X, long double Y){
            long double v = parseTerm(X,Y);
            while(true){
                skipSpaces();
                if(pos >= s.size()) break;
                char op = s[pos];
                if(op=='+' || op=='-'){
                    pos++;
                    long double rhs = parseTerm(X,Y);
                    if(op=='+') v += rhs;
                    else v -= rhs;
                } else break;
            }
            return v;
        }

        long double eval(long double X, long double Y){
            pos = 0;
            return parseExpression(X,Y);
        }
    };

    Parser parser(expr, pos);

    auto f = [&](long double X, long double Y)->long double{
        return parser.eval(X,Y);
    };

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    long double X = X0;
    long double Y = Y0;
    for(long long i=0;i<=n;i++){
        cout << (double)X << ' ' << (double)Y << "\n";
        if(i==n) break;
        Y = Y + h * f(X,Y);
        X = X + h;
    }

    return 0;
}