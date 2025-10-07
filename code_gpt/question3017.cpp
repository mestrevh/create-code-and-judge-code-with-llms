/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string nome;
    int idade;

    while (getline(cin, nome) && cin >> idade) {
        cin.ignore(); // Para ignorar nova linha após a idade
        int diasVividos = idade * 365;
        cout << nome << ", você já viveu " << diasVividos << " dias!" << endl;
    }

    return 0;
}
