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

    string s;
    while (cin >> s && s != "sair") {
        int countAt = 0;
        int countDot = 0;
        int posAt = -1;
        vector<int> posDots;

        for (int i = 0; i < (int)s.length(); ++i) {
            if (s[i] == '@') {
                countAt++;
                posAt = i;
            } else if (s[i] == '.') {
                countDot++;
                posDots.push_back(i);
            }
        }

        bool valid = true;
        if (countAt != 1 || countDot != 2) {
            valid = false;
        } else {
            int d1 = posDots[0];
            int d2 = posDots[1];
            
            // Rules check:
            // 1. At least 1 char before '@' (posAt > 0)
            // 2. At least 1 char between '@' and first '.' (d1 > posAt + 1)
            // 3. At least 1 char between first '.' and second '.' (d2 > d1 + 1)
            // 4. At least 1 char after second '.' (d2 < length - 1)
            if (posAt < 1 || d1 < posAt + 2 || d2 < d1 + 2 || d2 > (int)s.length() - 2) {
                valid = false;
            }
        }

        if (valid) {
            cout << "certo\n";
        } else {
            cout << "errado\n";
        }
    }

    return 0;
}