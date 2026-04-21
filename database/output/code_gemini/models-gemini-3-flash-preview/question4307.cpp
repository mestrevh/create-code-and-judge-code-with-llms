/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y;
    int c;
    if (!(cin >> x >> y >> c)) return 0;

    int qs = 0;
    if (x > 0 && y > 0) qs = 1;
    else if (x < 0 && y > 0) qs = 2;
    else if (x < 0 && y < 0) qs = 3;
    else if (x > 0 && y < 0) qs = 4;
    else {
        cout << "caminhada invalida" << endl;
        return 0;
    }

    int qt = 0;
    if (qs == 1) qt = 3;
    else if (qs == 2) qt = 4;
    else if (qs == 3) qt = 1;
    else if (qs == 4) qt = 2;

    bool adjacent = false;
    if (qs == 1 && (c == 2 || c == 4)) adjacent = true;
    else if (qs == 2 && (c == 1 || c == 3)) adjacent = true;
    else if (qs == 3 && (c == 2 || c == 4)) adjacent = true;
    else if (qs == 4 && (c == 1 || c == 3)) adjacent = true;

    if (!adjacent) {
        cout << "caminhada invalida" << endl;
        return 0;
    }

    long long tx = 0, ty = 0;
    if (qt == 1) { tx = 1; ty = 1; }
    else if (qt == 2) { tx = -1; ty = 1; }
    else if (qt == 3) { tx = -1; ty = -1; }
    else if (qt == 4) { tx = 1; ty = -1; }

    long long dx = abs(tx - x);
    long long dy = abs(ty - y);

    auto get_quadrant = [](long long qx, long long qy) {
        if (qx > 0 && qy > 0) return 1;
        if (qx < 0 && qy > 0) return 2;
        if (qx < 0 && qy < 0) return 3;
        if (qx > 0 && qy < 0) return 4;
        return 0;
    };

    int qp1 = get_quadrant(tx, y);
    int qp2 = get_quadrant(x, ty);

    if (qp2 != c && qp2 != 0) {
        cout << dy << " passos em y e " << dx << " passos em x" << endl;
    } else if (qp1 != c && qp1 != 0) {
        cout << dx << " passos em x e " << dy << " passos em y" << endl;
    } else {
        cout << "caminhada invalida" << endl;
    }

    return 0;
}