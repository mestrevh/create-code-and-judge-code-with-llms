/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matriz(n, vector<char>(m));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matriz[i][j];
    
    int T;
    cin >> T;

    while (T--) {
        int x, y, L;
        string S;
        cin >> x >> y >> S >> L;
        
        int dx = 0, dy = 0;
        if (S == "cima") dx = -1;
        else if (S == "baixo") dx = 1;
        else if (S == "esquerda") dy = -1;
        else if (S == "direita") dy = 1;

        bool desistir = false;

        while (true) {
            x += dx;
            y += dy;

            if (x < 0 || x >= n || y < 0 || y >= m) {
                break;
            }

            if (matriz[x][y] == '#') {
                L--;
            } else if (matriz[x][y] == '%') {
                L -= 2;
            }

            if (L < 0) {
                desistir = true;
                break;
            }
        }

        if (desistir) {
            cout << "Vou voltar pra Limoeiro..." << endl;
        } else {
            cout << "O amor está no ar!" << endl;
        }
    }

    return 0;
}
