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

    string d, s;
    if (!(cin >> d >> s)) return 0;

    unsigned char mapping[256];
    for (int i = 0; i < 256; i++) {
        mapping[i] = (unsigned char)i;
    }

    int len_d = (int)d.length();
    int len_s = (int)s.length();
    int mapping_limit = len_d < len_s ? len_d : len_s;

    for (int i = 0; i < mapping_limit; i++) {
        mapping[(unsigned char)d[i]] = (unsigned char)s[i];
    }

    int n;
    if (!(cin >> n)) return 0;

    string nick;
    while (n--) {
        if (!(cin >> nick)) break;
        for (char &c : nick) {
            c = (char)mapping[(unsigned char)c];
        }
        cout << nick << "\n";
    }

    return 0;
}