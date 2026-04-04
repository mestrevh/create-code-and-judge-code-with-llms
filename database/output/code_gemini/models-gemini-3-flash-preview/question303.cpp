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

    long long tempo, velocidade;
    if (!(cin >> tempo >> velocidade)) return 0;

    double distancia = (double)tempo * velocidade;
    double litros = distancia / 12.0;

    cout << fixed << setprecision(3) << litros << endl;

    return 0;
}