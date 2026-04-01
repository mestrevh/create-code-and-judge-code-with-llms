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

    string input;
    if (!(cin >> input)) {
        return 0;
    }

    if (input == "F") {
        cout << "Feminino" << endl;
    } else if (input == "M") {
        cout << "Masculino" << endl;
    } else {
        cout << "Sexo nao definido" << endl;
    }

    return 0;
}