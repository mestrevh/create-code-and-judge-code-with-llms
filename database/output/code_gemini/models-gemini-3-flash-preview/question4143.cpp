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

    double n1, n2;
    char op;

    if (!(cin >> n1 >> n2 >> op)) return 0;

    cout << fixed << setprecision(2);

    switch (op) {
        case '+':
            cout << n1 << " + " << n2 << " = " << (n1 + n2) << endl;
            break;
        case '-':
            cout << n1 << " - " << n2 << " = " << (n1 - n2) << endl;
            break;
        case '*':
            cout << n1 << " * " << n2 << " = " << (n1 * n2) << endl;
            break;
        case '/':
            cout << n1 << " / " << n2 << " = " << (n1 / n2) << endl;
            break;
        default:
            cout << "A operacao " << op << " eh invalida!" << endl;
            break;
    }

    return 0;
}