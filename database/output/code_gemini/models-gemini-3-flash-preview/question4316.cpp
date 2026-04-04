/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        string s;
        if (!(cin >> s)) break;

        reverse(s.begin(), s.end());

        size_t first_nonzero = s.find_first_not_of('0');
        if (first_nonzero == string::npos) {
            cout << "0\n";
        } else {
            cout << s.substr(first_nonzero) << "\n";
        }
    }

    return 0;
}