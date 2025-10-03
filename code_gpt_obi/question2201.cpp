/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int L, C;
    cin >> L >> C;
    int n1 = (L-1)*(C-1) + (L-1) + (C-1) + (L*C - 2*(L-1) - 2*(C-1) - 1);
    int n2 = 2*(L-1) + 2*(C-1);
    cout << n1 << endl;
    cout << n2 << endl;
    return 0;
}
