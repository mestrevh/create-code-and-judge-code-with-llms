/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    if (N <= 0) {
        cout << "Vazia" << endl;
        return 0;
    }
    
    int M1[10][10], M2[10][10], MR[10][10];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> M1[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> M2[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            MR[i][j] = M1[i][j] + M2[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cout << MR[i][j] << endl;

    return 0;
}
