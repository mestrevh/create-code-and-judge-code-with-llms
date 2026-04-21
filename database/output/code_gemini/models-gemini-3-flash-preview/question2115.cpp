/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x;
    if (cin >> x) {
        char buf[64];
        // Standard scientific notation with 4 decimal places
        sprintf(buf, "%.4e", x);
        string s = buf;

        // Ensure exponent has exactly 2 digits if it's currently 3 digits (common in some environments like Windows)
        // Scientific format: [-]d.dddde[+/-]ddd
        size_t ePos = s.find('e');
        if (ePos != string::npos) {
            // Case where exponent is 3 digits, like e+001 or e-001 (s.size() - ePos == 5)
            // We only erase the leading zero if there are three digits after the sign.
            if (s.size() - ePos == 5 && s[ePos + 2] == '0') {
                s.erase(ePos + 2, 1);
            }
        }

        string sig;
        if (x > 0) {
            sig = "+1";
        } else if (x < 0) {
            sig = "-1";
        } else {
            sig = "0";
        }

        // Output format: sinal(<formatted_x>) = <signal>
        printf("sinal(%s) = %s\n", s.c_str(), sig.c_str());
    }

    return 0;
}