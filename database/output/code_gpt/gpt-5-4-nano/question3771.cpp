/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

double distancia(double x0, double z0, double xf, double zf) {
    double dx = x0 - xf;
    double dz = z0 - zf;
    return sqrt(dx*dx + dz*dz);
}

double Calcula_tempo(double x0, double z0, double xf, double zf, double v) {
    double d = distancia(x0, z0, xf, zf);
    return d / v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x0, z0, xf, zf, v;
    if (!(cin >> x0 >> z0 >> xf >> zf >> v)) return 0;

    double horas = Calcula_tempo(x0, z0, xf, zf, v);

    cout.setf(std::ios::fixed);
    cout << setprecision(2);
    cout << "Milos esta no ponto (" << (long long) llround(x0) << ", " << (long long) llround(z0)
         << ") indo para (" << (long long) llround(xf) << ", " << (long long) llround(zf)
         << ") e provavelmente ira chegar em " << horas << " horas.";
    return 0;
}