/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (cin >> s) {
        string current = "";
        for (char c : s) {
            if (c == '.' || c == '-') {
                if (!current.empty()) {
                    cout << current << "\n";
                    current = "";
                }
            } else {
                current += c;
            }
        }
        if (!current.empty()) {
            cout << current << "\n";
        }
    }
    return 0;
}