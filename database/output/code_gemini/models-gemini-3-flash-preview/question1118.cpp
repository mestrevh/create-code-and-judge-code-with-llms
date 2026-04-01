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

    int n, m;
    if (!(cin >> n >> m)) return 0;

    string base, s1, s2;
    if (!(cin >> base >> s1 >> s2)) return 0;

    int len = (int)base.length();

    if (n <= 0 || n > len || m < 0 || m >= len) {
        cout << "TAMANHO INVALIDO" << endl;
        return 0;
    }

    string pref = base.substr(0, n);
    string suff = base.substr(m);

    string prefU = pref;
    for (char &c : prefU) {
        c = (char)toupper((unsigned char)c);
    }

    string suffU = suff;
    for (char &c : suffU) {
        c = (char)toupper((unsigned char)c);
    }

    cout << prefU << " :" << "\n";
    cout << pref << s1 << "\n";
    cout << pref << s2 << "\n\n";

    cout << suffU << " :" << "\n";
    cout << s1 << suff << "\n";
    cout << s2 << suff << endl;

    return 0;
}