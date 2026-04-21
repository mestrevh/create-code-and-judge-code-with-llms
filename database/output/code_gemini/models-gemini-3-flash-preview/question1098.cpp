/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int idade;
    if (!(cin >> idade)) return 0;

    if (idade < 5) {
        cout << "Idade invalida." << endl;
    } else if (idade >= 5 && idade <= 7) {
        cout << "Infantil A" << endl;
    } else if (idade >= 8 && idade <= 10) {
        cout << "Infantil B" << endl;
    } else if (idade >= 11 && idade <= 13) {
        cout << "Juvenil A" << endl;
    } else if (idade >= 14 && idade <= 17) {
        cout << "Juvenil B" << endl;
    } else if (idade >= 18 && idade <= 40) {
        cout << "Adulto" << endl;
    } else {
        cout << "Master" << endl;
    }

    return 0;
}