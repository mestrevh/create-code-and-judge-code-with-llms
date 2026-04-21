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

    char target;
    if (!(cin >> target)) {
        cout << -1 << "\n";
        return 0;
    }

    int n = (int)s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] == target) {
            cout << i << "\n";
        }
    }
    cout << -1 << "\n";

    return 0;
}