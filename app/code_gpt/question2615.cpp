/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int divida, pagamento;
    cin >> divida >> pagamento;

    while (divida > 0) {
        cout << "(antes) " << divida << endl;
        divida -= (divida < pagamento) ? divida : pagamento;
        cout << "(depois) " << divida << endl;
    }

    return 0;
}
