/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double xa, ya, xb, yb, xc, yc;
    if (!(cin >> xa >> ya >> xb >> yb >> xc >> yc)) return 0;

    double ux = xa - xb;
    double uy = ya - yb;
    double vx = xc - xb;
    double vy = yc - yb;

    double dot_product = ux * vx + uy * vy;
    double mag_u = sqrt(ux * ux + uy * uy);
    double mag_v = sqrt(vx * vx + vy * vy);

    double cos_theta = dot_product / (mag_u * mag_v);

    if (cos_theta > 1.0) cos_theta = 1.0;
    if (cos_theta < -1.0) cos_theta = -1.0;

    double theta_rad = acos(cos_theta);
    double theta_deg = theta_rad * 180.0 / acos(-1.0);

    cout << fixed << setprecision(2) << theta_deg << endl;

    return 0;
}