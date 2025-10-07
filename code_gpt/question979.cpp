/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros(4);
    for (int i = 0; i < 4; i++) {
        cin >> numeros[i];
    }
    sort(numeros.rbegin(), numeros.rend());
    for (int i = 0; i < 4; i++) {
        cout << numeros[i] << " ";
    }
    return 0;
}
