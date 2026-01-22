/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double v;
    cin >> v;

    double dist[3];
    int agua[3];

    for (int i = 0; i < 3; ++i) {
        cin >> dist[i] >> agua[i];
    }

    double total_time = 0;
    for (int i = 0; i < 3; ++i) {
        if (agua[i] == 0) {
            cout << "Nao vai ter como completar o percurso, RIP." << endl;
            return 0;
        }
        total_time += dist[i] / v;
    }

    cout << fixed << setprecision(2);
    cout << "O percurso sera completado em " << total_time << " segundos!" << endl;
    return 0;
}
