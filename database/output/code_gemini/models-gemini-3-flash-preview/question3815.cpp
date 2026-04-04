/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d = -1, m = -1, y = -1;
    bool hasD = (cin >> d) ? true : false;
    if (!hasD) return 0;

    bool hasM = (cin >> m) ? true : false;
    bool hasY = (cin >> y) ? true : false;

    if (d < 1 || d > 31) {
        cout << "Dia inexistente" << endl;
    } else if (!hasM || m < 1 || m > 12) {
        cout << "Mês inexistente" << endl;
    } else if (!hasY || y < 1900 || y > 2020) {
        cout << "Ano inexistente" << endl;
    } else {
        bool isLeap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));

        if (m == 2) {
            if (d == 29 && !isLeap) {
                cout << "Esse ano não é bissexto" << endl;
            } else if (d > (isLeap ? 29 : 28)) {
                cout << "Esse dia não existe nesse mês" << endl;
            } else {
                cout << "Data Validada" << endl;
            }
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            if (d > 30) {
                cout << "Esse dia não existe nesse mês" << endl;
            } else {
                cout << "Data Validada" << endl;
            }
        } else {
            // Months 1, 3, 5, 7, 8, 10, 12 (max days is 31, already checked d > 31)
            cout << "Data Validada" << endl;
        }
    }

    return 0;
}