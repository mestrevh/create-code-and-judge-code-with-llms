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
    if (cin >> s) {
        if (s.length() == 5) {
            if (s[0] == s[4] && s[1] == s[3]) {
                cout << "S" << endl;
            } else {
                cout << "N" << endl;
            }
        } else {
            // Handing case where input might be read as an integer with fewer than 5 digits due to leading zeros
            string padded = string(5 - s.length(), '0') + s;
            if (padded[0] == padded[4] && padded[1] == padded[3]) {
                cout << "S" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }

    return 0;
}