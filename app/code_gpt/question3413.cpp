/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i += 2) {
        if (i != 0) cout << "   ";
        cout << i;
    }
    cout << endl;
    return 0;
}
