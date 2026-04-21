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

    char d;
    string n;
    while (cin >> d >> n && (d != '0' || n != "0")) {
        string res = "";
        res.reserve(n.size());
        for (char c : n) {
            if (c != d) {
                res += c;
            }
        }

        if (res.empty()) {
            cout << "0\n";
            continue;
        }

        size_t first_non_zero = res.find_first_not_of('0');
        if (first_non_zero == string::npos) {
            cout << "0\n";
        } else {
            cout << res.substr(first_non_zero) << "\n";
        }
    }

    return 0;
}
_
