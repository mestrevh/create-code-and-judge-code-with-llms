/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double total;
    if (!(cin >> total)) return 0;

    cout << "Digite o valor total do premio em dinheiro:" << endl;
    cout << "Premio para o 1 lugar: R$ " << total * 0.6 << endl;
    cout << "Premio para o 2 lugar: R$ " << total * 0.3 << endl;
    cout << "Premio para o 3 lugar: R$ " << total * 0.1 << endl;

    return 0;
}