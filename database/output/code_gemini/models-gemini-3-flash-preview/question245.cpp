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
    if (!getline(cin, s)) return 0;

    // Remove possible carriage return from Windows-style line endings
    if (!s.empty() && s.back() == '\r') {
        s.pop_back();
    }

    char c;
    if (cin >> c) {
        size_t found = s.find(c);
        if (found != string::npos) {
            cout << (long long)found << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}