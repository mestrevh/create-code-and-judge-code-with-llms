/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

double distancia(double Xa, double Ya, double Xb, double Yb) {
    double dx = Xa - Xb;
    double dy = Ya - Yb;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    cout.setf(ios::fixed);
    cout << setprecision(2);
    
    for (int i = 0; i < N; i++) {
        long long Xa, Ya, Xb, Yb;
        cin >> Xa >> Ya >> Xb >> Yb;
        double ans = distancia((double)Xa, (double)Ya, (double)Xb, (double)Yb);
        cout << ans << "\n";
    }
    return 0;
}