/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string day;
    int effort = 0;

    for (int i = 0; i < 5; ++i) {
        cin >> day;
        if (day == "C") {
            int hours;
            cin >> hours;
            effort += hours * 3;
            if (i + 1 < 5) {
                cin >> day; // Next day input
                effort += (day == "C") ? (hours * 3) * 2 : stoi(day) * 2;
                i++; // Skip the next line since it's already processed
            }
        } else {
            int hours = stoi(day);
            if (i == 0) effort += hours * 2; // Monday
            else if (i == 4) effort += hours / 2; // Friday
            else effort += hours; // Tuesday, Wednesday, Thursday
        }
    }

    if (effort > 40) cout << "DESCANSE LEAFAR, JA FOI SUFICIENTE" << endl;
    else if (effort == 40) cout << "Descansou bem Leafar." << endl;
    else cout << "Só quer mamata..." << endl;

    return 0;
}
