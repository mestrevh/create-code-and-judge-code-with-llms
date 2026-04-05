/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name, indicator;
    double height;
    string min_name, max_name;
    double min_h = 1e18, max_h = -1e18;
    bool first = true;

    while (cin >> name >> height) {
        if (first || height < min_h) {
            min_h = height;
            min_name = name;
        }
        if (first || height > max_h) {
            max_h = height;
            max_name = name;
        }
        first = false;

        if (!(cin >> indicator)) break;

        string temp = indicator;
        for (char &c : temp) {
            c = (char)toupper((unsigned char)c);
        }
        if (temp == "FIM") break;
    }

    for (char &c : min_name) {
        c = (char)toupper((unsigned char)c);
    }
    for (char &c : max_name) {
        c = (char)toupper((unsigned char)c);
    }

    cout << min_name << "\n" << max_name << endl;

    return 0;
}