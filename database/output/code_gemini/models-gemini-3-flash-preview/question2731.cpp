/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

double find_maximum(double a, double b, double c, double d) {
    return max({a, b, c, d});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n1, n2, n3, n4;
    if (cin >> n1 >> n2 >> n3 >> n4) {
        cout << fixed << setprecision(2) << find_maximum(n1, n2, n3, n4) << "\n";
    }

    return 0;
}