/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

string decToBin(long long n) {
    if (n < 2) return string(1, (char)(n + '0'));
    return decToBin(n / 2) + (char)((n % 2) + '0');
}

long long binToDec(const string& s, int n) {
    if (n == 0) return 0;
    return (s[n - 1] - '0') + 2LL * binToDec(s, n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases;
    if (!(cin >> n_cases)) return 0;

    while (n_cases--) {
        string op, val_str;
        if (!(cin >> op >> val_str)) break;

        if (op == "dec") {
            try {
                long long decimal_val = stoll(val_str);
                cout << decToBin(decimal_val) << "\n";
            } catch (...) {
                // If stoll fails, it would imply invalid input format for 'dec'
            }
        } else if (op == "bin") {
            cout << binToDec(val_str, (int)val_str.length()) << "\n";
        } else {
            cout << "comando invalido." << "\n";
        }
    }

    return 0;
}