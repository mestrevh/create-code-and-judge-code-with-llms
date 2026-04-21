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
    if (!getline(cin, s)) return 0;

    int i1, f1, i2, f2;
    if (!(cin >> i1 >> f1 >> i2 >> f2)) return 0;

    if (i1 >= 0 && i1 < (int)s.length() && f1 >= i1) {
        cout << s.substr(i1, f1 - i1 + 1);
    }
    
    if (i2 >= 0 && i2 < (int)s.length() && f2 >= i2) {
        cout << s.substr(i2, f2 - i2 + 1);
    }

    cout << endl;

    return 0;
}