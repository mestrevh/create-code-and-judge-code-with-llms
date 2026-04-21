/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int code;
    while (cin >> code) {
        if (code == 2) {
            int quantity;
            if (cin >> quantity) {
                cout << "Você escolheu X-Tudo" << endl;
                cout << "Sua conta é de R$" << fixed << setprecision(2) << (double)quantity * 4.75 << endl;
            }
        } else {
            cout << "Código inválido" << endl;
            if (code == 0) {
                break;
            }
        }
    }

    return 0;
}