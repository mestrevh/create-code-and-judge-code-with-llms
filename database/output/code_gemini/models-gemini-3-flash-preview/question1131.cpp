/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string encrypt(string s) {
    int n = s.length();
    if (n == 0) return s;
    reverse(s.begin(), s.end());
    for (int i = 0; i + 1 < n; i += 2) {
        swap(s[i], s[i + 1]);
    }
    if (n % 2 != 0) {
        char last = s.back();
        s.pop_back();
        s.insert(s.begin(), last);
    }
    return s;
}

string decrypt(string s) {
    int n = s.length();
    if (n == 0) return s;
    if (n % 2 != 0) {
        char first = s[0];
        s.erase(0, 1);
        s.push_back(first);
    }
    for (int i = 0; i + 1 < n; i += 2) {
        swap(s[i], s[i + 1]);
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line1, line2;
    if (getline(cin, line1)) {
        cout << encrypt(line1) << "\n";
    }
    if (getline(cin, line2)) {
        cout << decrypt(line2) << "\n";
    }

    return 0;
}