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

    double v;
    if (!(cin >> v)) return 0;

    double d1, d2, d3;
    int w1, w2, w3;

    if (!(cin >> d1 >> w1 >> d2 >> w2 >> d3 >> w3)) return 0;

    if (w1 == 0 && w2 == 0 && w3 == 0) {
        cout << "Nao vai ter como completar o percurso, RIP." << endl;
    } else {
        double total_distance = d1 + d2 + d3;
        double time_taken = total_distance / v;
        cout << "O percurso sera completado em " << fixed << setprecision(2) << time_taken << " segundos!" << endl;
    }

    return 0;
}