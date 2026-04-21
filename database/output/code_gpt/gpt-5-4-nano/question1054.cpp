/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double r, angleDeg;
    if (!(cin >> r >> angleDeg)) return 0;
    
    const double pi = 3.14;
    double theta = angleDeg * pi / 180.0;
    double arc = r * theta;
    double area = (theta / (2.0 * pi)) * pi * r * r;
    
    cout << fixed << setprecision(2) << arc << "\n" << area;
    return 0;
}