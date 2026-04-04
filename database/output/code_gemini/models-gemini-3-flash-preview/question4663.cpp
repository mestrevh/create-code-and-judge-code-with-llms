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

    double total_effort = 0;
    bool double_next_day = false;

    for (int i = 0; i < 5; ++i) {
        string s;
        if (!(cin >> s)) break;

        double h = 0;
        double current_effort = 0;
        bool is_special_C = (s == "C");

        if (is_special_C) {
            if (!(cin >> h)) break;
            current_effort = h * 3.0;
        } else {
            h = stod(s);
            if (i == 0) { // Segunda-feira (Monday)
                current_effort = h * 2.0;
            } else if (i == 4) { // Sexta-feira (Friday)
                current_effort = h * 0.5;
            } else {
                current_effort = h;
            }
        }

        if (double_next_day) {
            current_effort *= 2.0;
            double_next_day = false;
        }

        if (is_special_C) {
            double_next_day = true;
        }

        total_effort += current_effort;
    }

    if (total_effort > 40.0) {
        cout << "DESCANSE LEAFAR, JA FOI SUFICIENTE" << endl;
    } else if (total_effort == 40.0) {
        cout << "Descansou bem Leafar." << endl;
    } else {
        cout << "Só quer mamata..." << endl;
    }

    return 0;
}