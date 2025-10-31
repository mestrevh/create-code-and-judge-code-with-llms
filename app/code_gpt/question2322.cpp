/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

void buscarArmario(const vector<vector<int>>& corredores, int corredor, int armario, int &corredorResultado, int &armarioResultado, bool &descoberto) {
    if (descoberto || corredor >= corredores.size()) return;
    if (armario >= corredores[corredores.size() - 1].size()) {
        buscarArmario(corredores, corredor + 1, 0, corredorResultado, armarioResultado, descoberto);
        return;
    }
    if (corredores[corredor][armario] < 0) {
        descoberto = true;
        return;
    }
    if (corredores[corredor][armario] == 0) {
        corredorResultado = corredor + 1;
        armarioResultado = armario + 1;
        return;
    }
    buscarArmario(corredores, corredor, armario + 1, corredorResultado, armarioResultado, descoberto);
}

int main() {
    int N, Y;
    cin >> N >> Y;
    
    if (N == 0 || Y == 0) {
        cout << "Sharpay endoidou!" << endl;
        return 0;
    }

    vector<vector<int>> corredores(N, vector<int>(Y));
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < Y; j++)
            cin >> corredores[i][j];

    int corredorResultado = -1, armarioResultado = -1;
    bool descoberto = false;

    buscarArmario(corredores, 0, 0, corredorResultado, armarioResultado, descoberto);

    if (descoberto) {
        cout << "Voce foi descoberto! Corra dancando Bop To the Top!!" << endl;
    } else if (corredorResultado == -1) {
        cout << "Sharpay endoidou!" << endl;
    } else {
        cout << "O armario a ser invadido fica no corredor " << corredorResultado << ", e e o armario de numero " << armarioResultado << "." << endl;
    }

    return 0;
}
