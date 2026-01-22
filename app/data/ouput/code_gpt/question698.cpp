/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int alturas[5];
    for (int i = 0; i < 5; i++) {
        cin >> alturas[i];
    }
    sort(alturas, alturas + 5);
    cout << alturas[0] << endl;
    cout << alturas[2] << endl;
    cout << alturas[4] << endl;
    return 0;
}
