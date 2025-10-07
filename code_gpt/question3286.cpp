/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int area, ceramica;
    cin >> area >> ceramica;
    
    int quantidade = ceil((double)area / ceramica);
    int precoTotal = quantidade * 25;
    
    cout << quantidade << endl;
    cout << precoTotal << endl;
    
    return 0;
}
