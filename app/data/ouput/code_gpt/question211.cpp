/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int mapa[100][100], total[100][100];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> mapa[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> total[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cout << mapa[i][j] + total[i][j] << " ";
    
    cout << endl;

    return 0;
}
