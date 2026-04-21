/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

void Plantar_e_Colher(int dia, int mes) {
    if (mes == 1) {
        cout << "Hora de plantar algodão e colher manga" << endl;
    } else if (mes == 2) {
        cout << "Hora de colher algodão" << endl;
    } else if (mes == 3) {
        cout << "Hora de plantar feijão" << endl;
    } else if (mes == 4) {
        cout << "Hora de colher milho" << endl;
    } else if (mes == 5) {
        cout << "Hora de plantar mandioca" << endl;
    } else if (mes == 6) {
        cout << "Hora de colher feijão" << endl;
    } else if (mes == 7) {
        cout << "Hora de plantar batata" << endl;
    } else if (mes == 8) {
        cout << "Hora de colher mandioca" << endl;
    } else if (mes == 9) {
        cout << "Hora de plantar café" << endl;
    } else if (mes == 10) {
        cout << "Hora de plantar milho e soja" << endl;
    } else if (mes == 11) {
        cout << "Hora de colher batata" << endl;
    } else if (mes == 12) {
        cout << "Hora de colher café" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dia, mes;
    if (cin >> dia >> mes) {
        Plantar_e_Colher(dia, mes);
    }

    return 0;
}