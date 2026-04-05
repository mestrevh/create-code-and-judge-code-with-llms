/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double X, Y, Z;
    if (!(cin >> X >> Y)) return 0;
    cin >> Z;
    
    long double rel = Y - X;
    long double timeHours = Z / rel;
    long double timeMinutes = timeHours * 60.0L;
    
    cout << (long long) llround(timeMinutes) << " minutos";
    return 0;
}