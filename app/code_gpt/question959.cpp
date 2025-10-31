/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    
    int count = 0;
    for (int i = 1; i <= Y; i += Z) {
        if (count > 0 && count % X == 0) cout << endl;
        cout << i << (i + Z <= Y ? " " : "");
        count++;
    }
    return 0;
}
