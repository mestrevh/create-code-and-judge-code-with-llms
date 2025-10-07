/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Pessoal, vai ter aula de IP aqui agora" << endl;
    cin >> n;

    vector<vector<int>> audacias(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        audacias[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> audacias[i][j];
        }
    }

    int expulsos = 0;
    int repeticoes = 0;

    for (int i = 0; i < n; ++i) {
        bool tem_ligado = false;
        for (int j = 0; j < audacias[i].size(); ++j) {
            if (audacias[i][j] > 0) {
                tem_ligado = true;
            }
        }
        
        if (tem_ligado) {
            repeticoes++;
            cout << "Desliga o monitor..." << endl;
            for (int j = 0; j < audacias[i].size(); ++j) {
                if (audacias[i][j] > 0) {
                    audacias[i][j] -= repeticoes;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < audacias[i].size(); ++j) {
            if (audacias[i][j] > 0) {
                expulsos++;
            }
        }
    }

    if (expulsos > 0) {
        cout << "Sergio pistolou e expulsou " << expulsos << " aluno(s) do laboratorio." << endl;
    }

    return 0;
}
