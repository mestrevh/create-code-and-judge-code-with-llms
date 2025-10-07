/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;
    for (int i = 1; i <= Y; i++) {
        cout << i;
        if (i % X == 0 || i == Y) cout << endl;
        else cout << " ";
    }
    return 0;
}
