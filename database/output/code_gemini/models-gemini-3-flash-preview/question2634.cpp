/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Digite o consumo de agua em m3:" << endl;
    
    int n;
    if (!(cin >> n)) return 0;

    if (n < 0) {
        cout << "Numeros negativos nao sao aceitos." << endl;
    } else {
        int valor = 7;
        
        if (n > 100) {
            valor += (n - 100) * 5;
            valor += (100 - 30) * 2;
            valor += (30 - 10) * 1;
        } else if (n > 30) {
            valor += (n - 30) * 2;
            valor += (30 - 10) * 1;
        } else if (n > 10) {
            valor += (n - 10) * 1;
        }
        
        cout << "O valor a ser pago e de R$ " << valor << "." << endl;
    }

    return 0;
}

