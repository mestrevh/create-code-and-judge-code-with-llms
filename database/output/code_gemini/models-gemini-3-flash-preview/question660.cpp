/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double g(double u, double D, double R) {
    double s = (D * sin(u)) / R;
    if (s > 1.0) s = 1.0;
    if (s < -1.0) s = -1.0;
    double val = R * R - D * D * sin(u) * sin(u);
    return R * R * asin(s) + D * sin(u) * sqrt(max(0.0, val));
}

double normalize_angle(double a) {
    a = fmod(a, 2.0 * M_PI);
    if (a < 0) a += 2.0 * M_PI;
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int X, Y, R;
    while (cin >> X >> Y >> R && (X != 0 || Y != 0 || R != 0)) {
        int P, Q, A, T;
        if (!(cin >> P >> Q >> A >> T)) break;
        
        double Xc = (double)X - (double)P;
        double Yc = (double)Y - (double)Q;
        double D = sqrt(Xc * Xc + Yc * Yc);
        double psi = atan2(Yc, Xc);
        double gamma = asin(R / D);
        
        double T_rad = (double)T * M_PI / 180.0;
        double A_rad = (double)A * M_PI / 180.0;
        double S1 = A_rad - T_rad / 2.0;
        double C1 = psi - gamma;
        
        double s1_rel = normalize_angle(S1 - C1);
        double s2_rel = s1_rel + T_rad;
        
        auto calc = [&](double l, double r) -> double {
            double il = max(l, 0.0);
            double ir = min(r, 2.0 * gamma);
            if (il < ir) {
                return g(ir - gamma, D, R) - g(il - gamma, D, R);
            }
            return 0.0;
        };
        
        double area = 0;
        if (s2_rel <= 2.0 * M_PI) {
            area += calc(s1_rel, s2_rel);
        } else {
            area += calc(s1_rel, 2.0 * M_PI);
            area += calc(0.0, s2_rel - 2.0 * M_PI);
        }
        
        cout << fixed << setprecision(1) << area << "\n";
    }
    
    return 0;
}