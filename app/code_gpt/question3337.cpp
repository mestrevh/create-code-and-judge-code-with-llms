/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int x0, x1, y0, y1, z0, z1;
    cin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;

    tuple<int, int, int> best = {INT_MAX, INT_MAX, INT_MAX};
    bool found = false;

    for (int x = x0; x <= x1; ++x) {
        for (int y = y0; y <= y1; ++y) {
            for (int z = z0; z <= z1; ++z) {
                if (x + y + z == n) {
                    found = true;
                    if (make_tuple(x, y, z) < best) {
                        best = {x, y, z};
                    }
                }
            }
        }
    }

    if (found) {
        cout << "S\n" << get<0>(best) << " " << get<1>(best) << " " << get<2>(best) << "\n";
    } else {
        cout << "N\n";
    }

    return 0;
}
