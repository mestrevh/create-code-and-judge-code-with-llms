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

    float h, r, cost_per_can;
    if (cin >> h >> r >> cost_per_can) {
        float pi = 3.14f;
        float area = 2.0f * pi * r * (r + h);
        float liters = area / 3.0f;
        float cans = liters / 5.0f;
        float total_cost = cans * cost_per_can;

        cout << fixed << setprecision(6);
        cout << area << "m2" << "\n";
        cout << liters << "l" << "\n";
        cout << cans << "\n";
        cout << "R$" << total_cost << "\n";
    }

    return 0;
}