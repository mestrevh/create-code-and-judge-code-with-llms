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
    while (cin >> s && s != "0") {
        size_t first_non_zero = s.find_first_not_of('0');
        
        if (first_non_zero == string::npos) {
            // Case where the number is composed only of zeros (e.g., "000")
            // Based on the rule: "Se o número for 000, ele deve imprimir [0]"
            cout << "[0]\n";
        } else {
            // Based on the rule: leading zeros are ignored (e.g., 001 becomes 1)
            // We iterate from the last digit back to the first non-zero digit
            for (int i = (int)s.size() - 1; i >= (int)first_non_zero; --i) {
                cout << "[" << s[i] << "]";
            }
            cout << "\n";
        }
    }

    return 0;
}