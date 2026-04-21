/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

string EstacaoAno(int d, int m) {
    if (m == 1 || m == 2) {
        return "VERAO";
    } else if (m == 3) {
        return (d <= 20) ? "VERAO" : "OUTONO";
    } else if (m == 4 || m == 5) {
        return "OUTONO";
    } else if (m == 6) {
        return (d <= 20) ? "OUTONO" : "INVERNO";
    } else if (m == 7 || m == 8) {
        return "INVERNO";
    } else if (m == 9) {
        return (d <= 20) ? "INVERNO" : "PRIMAVERA";
    } else if (m == 10 || m == 11) {
        return "PRIMAVERA";
    } else if (m == 12) {
        return (d <= 20) ? "PRIMAVERA" : "VERAO";
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dia, mes;
    if (cin >> dia >> mes) {
        cout << EstacaoAno(dia, mes) << endl;
    }

    return 0;
}