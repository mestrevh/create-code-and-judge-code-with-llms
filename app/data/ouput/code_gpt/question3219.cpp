/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int contarOcorrencias(const string& sequencia, char caractere) {
    int contador = 0;
    for (char c : sequencia) {
        if (c == caractere) {
            contador++;
        }
    }
    return contador;
}

int main() {
    string sequencia;
    char caractere;
    
    getline(cin, sequencia);
    cin >> caractere;

    int resultado = contarOcorrencias(sequencia, caractere);
    
    if (resultado > 0) {
        cout << "O caractere buscado ocorre " << resultado << " vezes na sequencia." << endl;
    } else {
        cout << "Caractere nao encontrado." << endl;
    }

    return 0;
}
