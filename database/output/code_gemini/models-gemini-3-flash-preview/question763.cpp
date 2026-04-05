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
    if (!getline(cin, s)) {
        return 0;
    }

    while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) {
        s.pop_back();
    }

    if (s.empty()) {
        return 0;
    }

    int n = s.length();
    bool is_palindrome = true;

    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            is_palindrome = false;
            break;
        }
    }

    if (is_palindrome) {
        cout << "SIM" << "\n";
        cout << n / 2 << "\n";
    } else {
        cout << "NAO" << "\n";
    }

    return 0;
}