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

    string nat;
    while (cin >> nat) {
        if (nat == "B" || nat == "E") {
            string occ;
            int qty, cal;
            if (!(cin >> occ >> qty >> cal)) break;

            if (nat == "E") {
                if (qty == 0) {
                    cout << "Liberado\n";
                } else {
                    cout << "Barrado\n";
                }
            } else { // nat == "B"
                bool lib = false;
                char o = (occ.empty() ? ' ' : occ[0]);
                
                if (o == 'M') {
                    lib = true;
                } else if (o == 'T' || o == 'O') {
                    if (qty == 0 || (qty == 1 && cal <= 22)) {
                        lib = true;
                    }
                } else if (o == 'C') {
                    if (qty == 0 || (qty <= 2 && cal <= 38)) {
                        lib = true;
                    }
                }

                if (lib) {
                    cout << "Liberado\n";
                } else {
                    cout << "Barrado\n";
                }
            }
        } else {
            cout << "Fim\n";
            break;
        }
    }

    return 0;
}