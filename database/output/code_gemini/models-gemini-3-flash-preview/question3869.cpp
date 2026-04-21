/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string trim(const string& s) {
    size_t f = s.find_first_not_of(" \t\r\n");
    if (f == string::npos) return "";
    size_t l = s.find_last_not_of(" \t\r\n");
    return s.substr(f, l - f + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;
    
    string line;
    getline(cin, line);

    for (int i = 0; i < N; ) {
        if (!getline(cin, line)) break;
        string tline = trim(line);
        if (tline.empty()) continue;
        
        i++;
        size_t sp = tline.find_first_of(" \t");
        if (sp == string::npos) continue;
        
        string instr = tline.substr(0, sp);
        string rest = tline.substr(sp + 1);
        
        size_t comma = rest.find(',');
        if (comma == string::npos) continue;
        
        string op1 = trim(rest.substr(0, comma));
        string op2 = trim(rest.substr(comma + 1));
        
        for (auto &c : instr) {
            c = (char)tolower((unsigned char)c);
        }
        
        if (instr == "mov") {
            cout << op1 << " = " << op2 << "\n";
        } else if (instr == "add") {
            cout << op1 << " += " << op2 << "\n";
        } else if (instr == "sub") {
            cout << op1 << " -= " << op2 << "\n";
        } else if (instr == "and") {
            cout << op1 << " = " << op1 << " & " << op2 << "\n";
        }
    }

    return 0;
}