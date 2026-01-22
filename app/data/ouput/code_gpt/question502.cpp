/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string tipo;
    double total = 0.0;
    int radioAM = 0, radioFM = 0, tvRegular = 0, tvNobre = 0, revista = 0, outdoor = 0;

    for (int i = 0; i < 7; i++) {
        cin >> tipo;
        if (tipo == "Rádio") {
            string faixa;
            cin >> faixa;
            if (faixa == "AM") {
                total += 300;
                radioAM++;
            } else if (faixa == "FM") {
                total += 500;
                radioFM++;
            }
        } else if (tipo == "TV") {
            int horario;
            cin >> horario;
            if (horario > 20) {
                total += 2000;
                tvNobre++;
            } else {
                total += 1200;
                tvRegular++;
            }
        } else if (tipo == "Revista") {
            total += 750;
            revista++;
        } else if (tipo == "Outdoor") {
            total += 1500;
            outdoor++;
        }
    }

    cout << fixed << setprecision(2) << total << endl;
    cout << radioAM << endl;
    cout << radioFM << endl;
    cout << tvRegular << endl;
    cout << tvNobre << endl;
    cout << revista << endl;
    cout << outdoor << endl;

    return 0;
}
