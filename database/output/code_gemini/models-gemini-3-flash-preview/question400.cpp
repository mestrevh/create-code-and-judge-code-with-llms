/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

double CalculaMulta(int velocidade) {
    if (velocidade <= 50) {
        return 0.0;
    } else if (velocidade <= 55) {
        return 230.0;
    } else if (velocidade <= 60) {
        return 340.0;
    } else {
        return (velocidade - 50) * 19.28;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int velocidade;
    if (cin >> velocidade) {
        cout << fixed << setprecision(2) << CalculaMulta(velocidade) << endl;
    }

    return 0;
}