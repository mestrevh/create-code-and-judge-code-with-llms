/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double budget, x, y, a, b, c, d;
    cin >> budget;
    cin >> x >> y >> a >> b >> c >> d;

    double price1, toll1, price2, toll2;
    cin >> price1 >> toll1;
    cin >> price2 >> toll2;

    double distance1 = sqrt(pow(a - x, 2) + pow(b - y, 2)) * 2; // ida e volta
    double distance2 = sqrt(pow(c - x, 2) + pow(d - y, 2)) * 2;

    double cost1 = (distance1 / 12) * price1 + toll1;
    double cost2 = (distance2 / 12) * price2 + toll2;

    bool canVisit1 = cost1 <= budget;
    bool canVisit2 = cost2 <= budget;

    if (canVisit1 && canVisit2) {
        cout << "Ele vai visitar os dois lugares\n";
        cout << fixed << setprecision(2) << min(cost1, cost2) << endl;
    } else if (canVisit1) {
        cout << "Ele vai para o destino 1\n";
        cout << fixed << setprecision(2) << cost1 << endl;
    } else if (canVisit2) {
        cout << "Ele vai para o destino 2\n";
        cout << fixed << setprecision(2) << cost2 << endl;
    } else {
        cout << "Ele vai ficar em casa\n";
        cout << -1 << endl;
    }

    return 0;
}
