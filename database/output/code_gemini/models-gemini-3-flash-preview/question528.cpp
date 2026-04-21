/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h1, m1, h2, m2, h3, m3;
    while (cin >> h1 >> m1 >> h2 >> m2 >> h3 >> m3) {
        bool v1 = (h1 >= 0 && h1 < 12);
        
        int t1 = h1 * 60 + m1;
        int t2 = h2 * 60 + m2;
        int t3 = h3 * 60 + m3;

        bool v2 = (t2 == (t1 + 192) % 1440);
        bool v3 = (t3 == (t2 + 1380) % 1440);

        if (v1) cout << "v\n"; else cout << "f\n";
        if (v2) cout << "v\n"; else cout << "f\n";
        if (v3) cout << "v\n"; else cout << "f\n";

        if (v1 && v2 && v3) {
            cout << "sucesso\n";
        } else {
            cout << "falha\n";
        }
    }

    return 0;
}