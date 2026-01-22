/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

void findStar(int x1, int y1, int x2, int y2, int x, int y, string &commands) {
    if (x1 == x2 && y1 == y2) return;
    
    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;

    if (x < midX && y < midY) {
        commands += '1'; // Primeiro quadrante
        findStar(x1, y1, midX, midY, x, y, commands);
    } 
    else if (x < midX && y >= midY) {
        commands += '2'; // Segundo quadrante
        findStar(x1, midY, midX, y2, x, y, commands);
    } 
    else if (x >= midX && y >= midY) {
        commands += '3'; // Terceiro quadrante
        findStar(midX, midY, x2, y2, x, y, commands);
    } 
    else {
        commands += '4'; // Quarto quadrante
        findStar(midX, y1, x2, midY, x, y, commands);
    }
}

int main() {
    int T;
    cin >> T;
    char matrix[256][256];
    int starX = -1, starY = -1;

    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < T; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == '*') {
                starX = i;
                starY = j;
            }
        }
    }

    string commands;
    findStar(0, 0, T, T, starX, starY, commands);
    if (commands.empty()) {
        cout << '0' << endl;
    } else {
        cout << commands << endl;
    }
    return 0;
}
