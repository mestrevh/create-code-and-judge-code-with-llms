/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int idade, sarampo = 0, hepatite = 0, ambas = 0;
    
    while (true) {
        cin >> idade;
        if (idade == 100) break;
        if (idade >= 3 && idade <= 6) sarampo++;
        if (idade >= 5 && idade <= 8) hepatite++;
        if (idade >= 5 && idade <= 6) ambas++;
    }
    
    cout << sarampo << endl;
    cout << hepatite << endl;
    cout << ambas << endl;
    
    return 0;
}
