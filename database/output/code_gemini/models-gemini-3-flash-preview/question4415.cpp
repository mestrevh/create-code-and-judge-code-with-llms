/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, z;
    if (!(cin >> x >> y >> z)) return 0;

    int ax = (x < 0) ? -x : x;
    int ay = (y < 0) ? -y : y;
    int az = (z < 0) ? -z : z;

    if (ax < ay && ax < az) {
        x = -x;
    } else if (ay < ax && ay < az) {
        y = -y;
    } else {
        z = -z;
    }

    int oct;
    if (z > 0) {
        if (x > 0 && y > 0) oct = 1;
        else if (x < 0 && y > 0) oct = 2;
        else if (x < 0 && y < 0) oct = 3;
        else oct = 4;
    } else {
        if (x > 0 && y > 0) oct = 5;
        else if (x < 0 && y > 0) oct = 6;
        else if (x < 0 && y < 0) oct = 7;
        else oct = 8;
    }

    cout << oct << endl;

    return 0;
}