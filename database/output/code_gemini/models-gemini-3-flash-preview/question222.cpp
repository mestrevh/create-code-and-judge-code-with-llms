/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cv, ce, cs, fv, fe, fs;
    if (cin >> cv >> ce >> cs >> fv >> fe >> fs) {
        int pc = (cv * 3) + ce;
        int pf = (fv * 3) + fe;

        if (pc > pf) {
            cout << "C\n";
        } else if (pf > pc) {
            cout << "F\n";
        } else {
            if (cs > fs) {
                cout << "C\n";
            } else if (fs > cs) {
                cout << "F\n";
            } else {
                cout << "=\n";
            }
        }
    }

    return 0;
}