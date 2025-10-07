/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    vector<string> livros(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, livros[i]);
    }

    string livro_procurado;
    getline(cin, livro_procurado);

    bool encontrado = false;
    for (const string& livro : livros) {
        if (livro == livro_procurado) {
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        cout << "Sim" << endl;
    } else {
        cout << "Não" << endl;
    }

    return 0;
}
