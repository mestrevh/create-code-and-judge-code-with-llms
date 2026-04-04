/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

string r(const string& s, int i) {
    if (i >= (int)s.length()) return "";
    int j = i + 1;
    while (j < (int)s.length() && s[j] == s[i]) {
        j++;
    }
    string res = "";
    res += s[i];
    return res + r(s, j);
}

string eliminar_repetidos(string txt) {
    return r(txt, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    while (getline(cin, line) && line != "*") {
        cout << eliminar_repetidos(line) << "\n";
    }
    return 0;
}