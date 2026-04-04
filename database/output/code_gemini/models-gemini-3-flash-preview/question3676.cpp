/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double budget;
    if (!(cin >> budget)) return 0;

    double x, y, a, b, c, d;
    if (!(cin >> x >> y >> a >> b >> c >> d)) return 0;

    double g1, p1, g2, p2;
    if (!(cin >> g1 >> p1)) return 0;
    if (!(cin >> g2 >> p2)) return 0;

    double dist1 = sqrt((a - x) * (a - x) + (b - y) * (b - y));
    double dist2 = sqrt((c - x) * (c - x) + (d - y) * (d - y));

    double cost1 = (dist1 / 6.0) * g1 + p1;
    double cost2 = (dist2 / 6.0) * g2 + p2;

    if (cost1 + cost2 <= budget + 1e-9) {
        cout << "Ele vai visitar os dois lugares" << endl;
        cout << fixed << setprecision(2) << (cost1 + cost2) << endl;
    } else {
        bool can1 = (cost1 <= budget + 1e-9);
        bool can2 = (cost2 <= budget + 1e-9);

        if (can1 && can2) {
            if (abs(cost1 - cost2) < 1e-9) {
                cout << "Tanto faz..." << endl;
                cout << fixed << setprecision(2) << cost1 << endl;
            } else if (cost1 < cost2) {
                cout << "Ele vai para o destino 1" << endl;
                cout << fixed << setprecision(2) << cost1 << endl;
            } else {
                cout << "Ele vai para o destino 2" << endl;
                cout << fixed << setprecision(2) << cost2 << endl;
            }
        } else if (can1) {
            cout << "Ele vai para o destino 1" << endl;
            cout << fixed << setprecision(2) << cost1 << endl;
        } else if (can2) {
            cout << "Ele vai para o destino 2" << endl;
            cout << fixed << setprecision(2) << cost2 << endl;
        } else {
            cout << "Ele vai ficar em casa" << endl;
            cout << -1 << endl;
        }
    }

    return 0;
}