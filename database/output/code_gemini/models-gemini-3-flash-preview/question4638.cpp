/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!getline(cin, s)) {
        cout << "fracasso" << endl;
        return 0;
    }

    size_t first = s.find_first_not_of(' ');
    if (first == string::npos) {
        cout << "fracasso" << endl;
        return 0;
    }
    size_t last = s.find_last_not_of(' ');
    string t = s.substr(first, (last - first + 1));

    if (t.length() < 10) {
        cout << "fracasso" << endl;
        return 0;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool onlyAlnum = true;

    for (char c : t) {
        if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (isdigit(c)) hasDigit = true;
        else {
            onlyAlnum = false;
            break;
        }
    }

    if (!hasUpper || !hasLower || !hasDigit || !onlyAlnum) {
        cout << "fracasso" << endl;
        return 0;
    }

    string forbidden[] = {"123", "321", "000", "abc"};
    string prefix = t.substr(0, 3);
    string suffix = t.substr(t.length() - 3);

    for (const string& f : forbidden) {
        if (prefix == f || suffix == f) {
            cout << "fracasso" << endl;
            return 0;
        }
    }

    cout << "sucesso" << endl;

    return 0;
}