/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string letra, frase;
    cin >> letra;
    cin.ignore();
    getline(cin, frase);

    size_t pos = frase.find(letra);
    if (pos != string::npos) {
        cout << pos + 1 << endl;
    } else {
        cout << "a frase nao possui a letra" << endl;
    }

    return 0;
}
