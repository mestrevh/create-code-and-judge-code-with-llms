/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> matriz(4, vector<int>(4, 0));
    char movimentos[20];
    for (int i = 0; i < 20; i++) {
        cin >> movimentos[i];
    }
    
    int x = 0, y = 0;
    for (int i = 0; i < 20; i++) {
        if (movimentos[i] == 'c') x--;
        else if (movimentos[i] == 'b') x++;
        else if (movimentos[i] == 'e') y--;
        else if (movimentos[i] == 'd') y++;
        
        if (x >= 0 && x < 4 && y >= 0 && y < 4) {
            matriz[x][y]++;
        }
    }
    
    int maxContagem = 0, coordX = 0, coordY = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matriz[i][j] > maxContagem) {
                maxContagem = matriz[i][j];
                coordX = i;
                coordY = j;
            }
        }
    }
    
    cout << "Coordenada X:" << coordX << ", Y:" << coordY << endl;
    return 0;
}
