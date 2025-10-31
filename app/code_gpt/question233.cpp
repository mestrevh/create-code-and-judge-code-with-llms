/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    unordered_map<string, int> pontos;

    for (int i = 0; i < m; ++i) {
        string palavra;
        int valor;
        cin >> palavra >> valor;
        pontos[palavra] = valor;
    }
    
    cin.ignore();
    
    for (int i = 0; i < n; ++i) {
        string descricao;
        int salario = 0;
        
        while (true) {
            getline(cin, descricao);
            if (descricao == ".") break;
            stringstream ss(descricao);
            string palavra;
            while (ss >> palavra) {
                salario += pontos[palavra];
            }
        }
        
        cout << salario << endl;
    }
    
    return 0;
}
