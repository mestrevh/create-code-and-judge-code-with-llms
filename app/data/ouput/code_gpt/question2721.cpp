/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int L, C;
    cin >> L >> C;
    int A[26][26], B[26][26], result[26][26];

    for (int i = 0; i < L; i++)
        for (int j = 0; j < C; j++)
            cin >> A[i][j];

    for (int i = 0; i < L; i++)
        for (int j = 0; j < C; j++)
            cin >> B[i][j];

    for (int i = 0; i < L; i++)
        for (int j = 0; j < C; j++)
            result[i][j] = A[i][j] + B[i][j];

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cout << result[i][j];
            if (j < C - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
