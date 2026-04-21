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
    while (getline(cin, s)) {
        // Remove potential trailing carriage returns from different OS environments
        while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) {
            s.pop_back();
        }

        // Termination condition check
        if (s == "FIM") {
            break;
        }

        // According to rules, an empty string is not a valid number
        if (s.empty()) {
            cout << "ERRO\n";
            continue;
        }

        string res = "";
        bool err = false;

        for (char c : s) {
            if (c >= '0' && c <= '9') {
                res += c;
            } else if (c == 'o' || c == 'O') {
                res += '0';
            } else if (c == 'l') {
                res += '1';
            } else {
                // Character not permitted
                err = true;
                break;
            }
        }

        if (err) {
            cout << "ERRO\n";
        } else {
            // Processing successful, now format the integer
            // Removing leading zeros is standard for integer representation
            size_t first_nonzero = res.find_first_not_of('0');
            if (first_nonzero == string::npos) {
                // If the string consists only of zeros, the value is 0
                cout << "0\n";
            } else {
                // Print substring starting from the first non-zero digit
                cout << res.substr(first_nonzero) << "\n";
            }
        }
    }

    return 0;
}