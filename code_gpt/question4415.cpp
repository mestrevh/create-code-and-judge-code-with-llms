/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int octant;
    if (abs(x) < abs(y) && abs(x) < abs(z)) {
        octant = (x > 0) ? (y > 0 ? 1 : 4) : (y > 0 ? 2 : 3);
    } else if (abs(y) < abs(x) && abs(y) < abs(z)) {
        octant = (y > 0) ? (x > 0 ? 1 : 2) : (x > 0 ? 4 : 3);
    } else {
        octant = (z > 0) ? (x > 0 ? 1 : 2) : (x > 0 ? 4 : 3);
    }

    cout << octant << endl;
    return 0;
}
