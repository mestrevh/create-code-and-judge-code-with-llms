/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int L, D, K, P;
    cin >> L >> D >> K >> P;
    
    int pedágios = L / D;
    int custoGasolina = L * K;
    int custoPedágios = pedágios * P;

    cout << custoGasolina + custoPedágios << endl;
    return 0;
}
