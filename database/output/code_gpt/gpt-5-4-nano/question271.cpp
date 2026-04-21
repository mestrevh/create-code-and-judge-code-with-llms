/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double r_cm;
    if (!(cin >> r_cm)) return 0;
    
    double r_m = r_cm / 100.0;
    double area = 3.14159 * r_m * r_m;
    
    cout << "Area = " << fixed << setprecision(4) << area << "\n";
    return 0;
}