/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int par[5], impar[5], p = 0, i = 0;
    for (int n = 0; n < 15; n++) {
        int num;
        cin >> num;
        if (num % 2 == 0) {
            par[p++] = num;
            if (p == 5) {
                for (int j = 0; j < p; j++)
                    cout << "par[" << j << "] = " << par[j] << endl;
                p = 0;
            }
        } else {
            impar[i++] = num;
            if (i == 5) {
                for (int j = 0; j < i; j++)
                    cout << "impar[" << j << "] = " << impar[j] << endl;
                i = 0;
            }
        }
    }
    for (int j = 0; j < i; j++)
        cout << "impar[" << j << "] = " << impar[j] << endl;
    for (int j = 0; j < p; j++)
        cout << "par[" << j << "] = " << par[j] << endl;
    return 0;
}
