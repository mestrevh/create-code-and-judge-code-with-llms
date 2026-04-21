/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2, o1, o2;
    int f;

    while (cin >> s1 >> s2 >> f >> o1 >> o2) {
        int r1 = (int)s1[0];
        int r2 = (int)s2[0];
        int ro1 = (int)o1[0];
        int ro2 = (int)o2[0];

        int d1 = min(abs(ro1 - r1), abs(ro1 - r2));
        int d2 = min(abs(ro2 - r1), abs(ro2 - r2));

        if (d1 < d2) {
            cout << "A opcao 1 e a mais segura\n";
        } else if (d2 < d1) {
            cout << "A opcao 2 e a mais segura\n";
        } else {
            int rf = (f == 1 ? r1 : r2);
            int df1 = abs(ro1 - rf);
            int df2 = abs(ro2 - rf);

            if (df1 < df2) {
                cout << "A opcao 1 e a mais segura\n";
            } else if (df2 < df1) {
                cout << "A opcao 2 e a mais segura\n";
            } else {
                cout << "Vou fechar os olhos e decidir\n";
            }
        }
    }

    return 0;
}