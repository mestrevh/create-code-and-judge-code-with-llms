/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

char shift_char(char c, int d) {
    int val = c - 'A';
    int result = (val + d) % 26;
    if (result < 0) result += 26;
    return (char)(result + 'A');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a1, a2, b1, b2, c1, c2;
    char m1, m2;
    int d1, d2;

    if (!(cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> m1 >> m2 >> d1 >> d2)) return 0;

    double p1 = (a1 + b1 + c1) / 3.0;
    double p2 = (a2 + b2 + c2) / 3.0;

    char f1 = shift_char(m1, d1);
    char f2 = shift_char(m2, d2);

    cout << "A pista esta na coordenada: (" << fixed << setprecision(2) << p1 << ", " << p2 << ") e o cod e: " << f1 << f2 << endl;

    return 0;
}