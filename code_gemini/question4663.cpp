/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int total_esforco = 0;
    string input;
    bool c_day = false;

    for (int i = 0; i < 5; ++i) {
        cin >> input;
        if (input == "C") {
            c_day = true;
            int horas_c;
            cin >> horas_c;
            total_esforco += horas_c * 3;
        } else {
            int horas = stoi(input);
            if (i == 0 || (c_day && i != 4)) {
                total_esforco += horas * 2;
            } else if (i == 4) {
                total_esforco += horas / 2;
            } else {
                total_esforco += horas;
            }
            c_day = false;
        }
    }

    if (total_esforco > 40) {
        cout << "DESCANSE LEAFAR, JA FOI SUFICIENTE" << endl;
    } else if (total_esforco == 40) {
        cout << "Descansou bem Leafar." << endl;
    } else {
        cout << "Só quer mamata..." << endl;
    }

    return 0;
}
