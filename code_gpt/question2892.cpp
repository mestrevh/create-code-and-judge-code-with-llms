/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cout << "Digite a ordem N da matriz:" << endl;
    cin >> N;

    int matrix[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) 
                matrix[i][j] = 1;
            else 
                matrix[i][j] = -10;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(7) << left << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
