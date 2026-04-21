/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char gender;
    if (cin >> gender) {
        if (gender == 'M' || gender == 'm') {
            cout << "Masculino" << endl;
        } else if (gender == 'F' || gender == 'f') {
            cout << "Feminino" << endl;
        } else {
            cout << "Genero nao especificado" << endl;
        }
    }

    return 0;
}