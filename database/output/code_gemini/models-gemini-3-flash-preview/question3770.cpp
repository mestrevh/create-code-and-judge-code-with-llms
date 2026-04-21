/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        for (char &c : s) {
            c = (char)tolower((unsigned char)c);
        }
        if (s.empty()) return 0;
        string r = s;
        reverse(r.begin(), r.end());
        cout << s << s << s[0] << r << r << endl;
    }

    return 0;
}