/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> parede(m, vector<char>(n));
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> parede[i][j];

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if (parede[i][j] == 'o') {
                int x = i;
                while (x < m) {
                    if (parede[x][j] == '#') break;
                    parede[x][j] = 'o';
                    x++;
                    if (j > 0 && parede[x][j - 1] == '#') j++;
                    else if (j < n - 1 && parede[x][j + 1] == '#') j--;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << parede[i][j];
        cout << endl;
    }
    
    return 0;
}
