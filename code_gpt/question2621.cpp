/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    int M[100][100];

    for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++)
            cin >> M[i][j];

    for (int j = 0; j < T; j++) {
        for (int i = 0; i < T; i++) {
            if (M[i][j] < 0)
                cout << M[i][j] * 2;
            else
                cout << M[i][j];
            if (i != T - 1)
                cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
