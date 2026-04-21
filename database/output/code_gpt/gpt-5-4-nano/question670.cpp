/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double ax, ay, bx, by, cx, cy;
    if (!(cin >> ax >> ay)) return 0;
    cin >> bx >> by >> cx >> cy;

    double v1x = ax - bx, v1y = ay - by;
    double v2x = cx - bx, v2y = cy - by;

    double dot = v1x * v2x + v1y * v2y;
    double n1 = hypot(v1x, v1y);
    double n2 = hypot(v2x, v2y);

    double cosang = dot / (n1 * n2);
    cosang = max(-1.0, min(1.0, cosang));

    double ang = acos(cosang) * 180.0 / acos(-1.0);

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << ang << "\n";
    return 0;
}