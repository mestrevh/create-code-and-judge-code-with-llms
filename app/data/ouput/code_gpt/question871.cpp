/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L, C;
    cin >> L >> C;
    
    vector<vector<int>> matriz(L, vector<int>(C));
    int somaPrincipal = 0, somaSecundaria = 0, menoresZero = 0, maioresZero = 0;

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> matriz[i][j];
            if (matriz[i][j] < 0) menoresZero++;
            if (matriz[i][j] > 0) maioresZero++;
        }
    }

    cout << "Matriz formada:\n";
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << matriz[i][j];
            if (j < C - 1) cout << " ";
        }
        cout << "\n";
    }

    if (L == C) {
        for (int i = 0; i < L; ++i) {
            somaPrincipal += matriz[i][i];
            somaSecundaria += matriz[i][L - i - 1];
        }
        cout << "A diagonal principal e secundaria tem valor(es) " << somaPrincipal << " e " << somaSecundaria << " respectivamente.\n";
    } else {
        cout << "A diagonal principal e secundaria nao pode ser obtida.\n";
    }

    cout << "A matriz possui " << menoresZero << " numero(s) menor(es) que zero.\n";
    cout << "A matriz possui " << maioresZero << " numero(s) maior(es) que zero.\n";

    return 0;
}
