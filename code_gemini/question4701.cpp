/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int contar_palavras_na_frase(string palavra, string frase) {
    int contador = 0;
    stringstream ss(frase);
    string temp;
    while (ss >> temp) {
        if (temp == palavra) {
            contador++;
        }
    }
    return contador;
}

int main() {
    string palavra, frase;
    getline(cin, palavra);
    getline(cin, frase);
    cout << contar_palavras_na_frase(palavra, frase) << endl;
    return 0;
}
