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

    int n;
    if (!(cin >> n)) return 0;

    string s;
    if (!(cin >> s)) return 0;

    long long x;
    if (!(cin >> x)) return 0;

    int shift = (int)((x % 26 + 26) % 26);

    for (int i = 0; i < n && i < (int)s.length(); ++i) {
        s[i] = (char)('a' + (s[i] - 'a' + shift) % 26);
    }

    cout << s << endl;

    return 0;
}