/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matriz(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matriz[i][j];

    for (int j = 0; j < m; ++j) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; ++i) {
                if (matriz[i][j] == 1)
                    cout << "Desliga o farol cidadao ( ._.)" << endl;
                else
                    cout << "Queria que todo mundo fosse assim" << endl;
            }
        } else {
            for (int i = n - 1; i >= 0; --i) {
                if (matriz[i][j] == 1)
                    cout << "Desliga o farol cidadao ( ._.)" << endl;
                else
                    cout << "Queria que todo mundo fosse assim" << endl;
            }
        }
    }
    return 0;
}
