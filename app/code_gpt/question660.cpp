/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;

double calculate_area(double R, double angle1, double angle2) {
    double sector_area = (angle2 - angle1) / 360.0 * PI * R * R;
    return sector_area > 0 ? sector_area : 0;
}

int main() {
    int X, Y, R, P, Q, A, T;
    while (true) {
        cin >> X >> Y >> R;
        if (X == 0 && Y == 0 && R == 0) break;
        cin >> P >> Q >> A >> T;
        
        double dx = P - X;
        double dy = Q - Y;
        double dist_sq = dx * dx + dy * dy;
        double R_sq = R * R;

        if (dist_sq <= R_sq) continue;

        double angle_cannon = atan2(dy, dx) * 180 / PI;
        while (angle_cannon < 0) angle_cannon += 360;

        double start_angle = A - T / 2.0;
        double end_angle = A + T / 2.0;

        while (start_angle < 0) start_angle += 360;
        while (end_angle < 0) end_angle += 360;
        
        start_angle = fmod(start_angle, 360);
        end_angle = fmod(end_angle, 360);

        double destroyed_area = 0.0;

        if (start_angle < end_angle) {
            if (angle_cannon >= start_angle && angle_cannon <= end_angle) {
                destroyed_area = calculate_area(R, start_angle, end_angle);
            }
        } else {
            if (angle_cannon >= start_angle || angle_cannon <= end_angle) {
                destroyed_area += calculate_area(R, start_angle, 360);
                destroyed_area += calculate_area(R, 0, end_angle);
            }
        }

        cout << fixed << setprecision(1) << destroyed_area << endl;
    }
    return 0;
}
