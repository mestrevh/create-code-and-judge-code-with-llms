/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

bool is_sym(char c) {
    return (c == '*' || c == ')' || c == '$' || c == '!' || c == '+' ||
            c == '@' || c == '-' || c == '/' || c == '(' || c == '%' ||
            c == ',' || c == '.' || c == '?');
}

char dig_to_s(char c) {
    if (c == '0') return '*';
    if (c == '1') return ')';
    if (c == '2') return '$';
    if (c == '3') return '!';
    if (c == '4') return '+';
    if (c == '5') return '@';
    if (c == '6') return '-';
    if (c == '7') return '/';
    if (c == '8') return '(';
    if (c == '9') return '%';
    return ' ';
}

string trans(string s) {
    string r = "";
    int cnt = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        char c = s[i];
        if (is_sym(c)) {
            cnt++;
        } else if (c == ' ') {
            continue;
        } else if (c >= '0' && c <= '9') {
            r += dig_to_s(c);
        } else if (c >= 'A' && c <= 'Z') {
            int v = c - 'A' + 1;
            if (v >= 10) {
                r += (char)((v / 10) + '0');
                r += (char)((v % 10) + '0');
            } else {
                r += (char)(v + '0');
            }
        } else if (c >= 'a' && c <= 'z') {
            if (cnt % 2 == 0) {
                r += (char)(c - 'a' + 'A');
            } else {
                r += c;
            }
        }
    }
    return r;
}

void rec() {
    string s;
    if (getline(cin, s)) {
        string t = trans(s);
        rec();
        cout << t << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    rec();
    return 0;
}