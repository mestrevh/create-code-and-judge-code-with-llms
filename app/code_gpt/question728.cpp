/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

double velkmh(double V0, double A, double T) {
    return 3.6 * (V0 + A * T);
}

int main() {
    double V0[3], A[3], T[3], velocities[3];

    for (int i = 0; i < 3; ++i) {
        cin >> V0[i] >> A[i] >> T[i];
        velocities[i] = velkmh(V0[i], A[i], T[i]);
    }

    double min_velocity = *min_element(velocities, velocities + 3);
    cout << fixed << setprecision(1) << min_velocity << endl;

    return 0;
}
