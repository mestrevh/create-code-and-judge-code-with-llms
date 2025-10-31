/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int ano;
    cin >> ano;
    
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        cout << "BISSEXTO" << endl;
    } else {
        cout << "NAOBISSEXTO" << endl;
    }
    
    return 0;
}
