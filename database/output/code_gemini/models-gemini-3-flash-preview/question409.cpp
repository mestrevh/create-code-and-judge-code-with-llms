/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int SerieMiguelito(int n) {
    if (n <= 1) {
        return 3;
    }
    if (n % 2 == 0) {
        return SerieMiguelito(n - 1) + 4;
    } else {
        return SerieMiguelito(n - 1) + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        cout << SerieMiguelito(n) << endl;
    }

    return 0;
}