/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int caso = 1; caso <= t; caso++) {
        int a, b, k;
        cin >> a >> b >> k;
        cout << "Caso " << caso << endl;

        vector<pair<int, int>> points(k);
        for (int i = 0; i < k; i++) {
            cin >> points[i].first >> points[i].second;
        }

        for (const auto& point : points) {
            int x = point.first, y = point.second;
            int frontier_value = a * x + b;
            if (y == frontier_value) {
                cout << "Mesmo lado da fronteira" << endl;
            } else if ((y > frontier_value && a > 0) || (y < frontier_value && a < 0)) {
                cout << "Lados opostos da fronteira" << endl;
            } else {
                cout << "Mesmo lado da fronteira" << endl;
            }
        }
    }
    return 0;
}
