/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int SerieMiguelito(int n) {
    if (n == 0) return 3;
    if (n == 1) return 7;
    return (n % 2 == 0) ? SerieMiguelito(n - 2) + 4 : SerieMiguelito(n - 2) + 1;
}

int main() {
    int n;
    cin >> n;
    cout << SerieMiguelito(n) << endl;
    return 0;
}
