/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string sex_str;
    int corte_m = 0, barba_m = 0;
    double revenue = 0.0;

    while (cin >> sex_str) {
        char sex = (char)tolower(sex_str[0]);
        if (sex != 'm' && sex != 'f') break;

        string service;
        cin >> service;
        for (auto &c : service) c = (char)tolower(c);

        if (sex == 'm') {
            if (service == "corte") {
                corte_m++;
                revenue += 25.0;
            } else if (service == "barba") {
                barba_m++;
                revenue += 15.0;
            }
        } else if (sex == 'f') {
            if (service == "corte") {
                revenue += 40.0;
            } else if (service == "penteado") {
                revenue += 50.0;
            } else if (service == "maquiagem") {
                revenue += 70.0;
            }
        }
    }

    if (corte_m > barba_m) {
        cout << "CORTE" << endl;
    } else if (barba_m > corte_m) {
        cout << "BARBA" << endl;
    } else {
        cout << "AMBOS" << endl;
    }

    cout << fixed << setprecision(2) << revenue << endl;

    return 0;
}