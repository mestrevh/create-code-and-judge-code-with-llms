/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    int matriz[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            matriz[i][j] = i * N + j + 1;

    cout << "Matriz:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(3) << matriz[i][j];
        cout << endl;
    }

    cout << "\nDiagonal Principal:\n";
    for (int i = 0; i < N; i++)
        cout << setw(3) << matriz[i][i] << endl;

    cout << "\nDiagonal Secundaria:\n";
    for (int i = 0; i < N; i++)
        cout << setw(3) << matriz[i][N - 1 - i] << endl;

    return 0;
}
