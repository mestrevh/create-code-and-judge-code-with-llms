/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int L, C;
    char X;
    cin >> L >> C >> X;
    
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cout << X;
        }
        cout << endl;
    }
    return 0;
}
