/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        string s;
        if (!(cin >> s)) break;

        int m[256];
        for (int i = 0; i < 256; i++) {
            m[i] = -1;
        }

        int count = 0;
        string res = "";
        res.reserve(s.length());
        
        for (char c : s) {
            unsigned char uc = (unsigned char)c;
            if (m[uc] == -1) {
                m[uc] = count++;
            }
            res += (char)('a' + m[uc]);
        }
        cout << res << "\n";
    }

    return 0;
}