/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double ingredientes[3][4], precos[4], custos[3] = {0};

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> ingredientes[i][j];

    for (int i = 0; i < 4; ++i)
        cin >> precos[i];

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            custos[i] += ingredientes[i][j] * precos[j];

    cout << fixed << setprecision(2);
    for (int i = 0; i < 3; ++i)
        cout << custos[i] << endl;

    return 0;
}
