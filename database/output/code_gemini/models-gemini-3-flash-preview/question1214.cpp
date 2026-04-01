/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string map_digit(char c) {
    if (c == '0') return "*";
    if (c == '1') return ")";
    if (c == '2') return "$";
    if (c == '3') return "!";
    if (c == '4') return "+";
    if (c == '5') return "@";
    if (c == '6') return "-";
    if (c == '7') return "/";
    if (c == '8') return "(";
    if (c == '9') return "%";
    return "";
}

string process(const string& s) {
    string res = "";
    int symbols = 0;
    for (char c : s) {
        if (isupper(c)) {
            res += to_string((int)(c - 'A' + 1));
        } else if (islower(c)) {
            if (symbols % 2 == 0) res += (char)toupper(c);
            else res += c;
        } else if (isdigit(c)) {
            res += map_digit(c);
        } else if (isspace(c)) {
            continue;
        } else {
            symbols++;
        }
    }
    return res;
}

void solve_recursive() {
    string line;
    if (!getline(cin, line)) return;
    string processed = process(line);
    solve_recursive();
    cout << processed << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve_recursive();
    return 0;
}