/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n1, n2, n3;
    double w1, w2, w3;

    if (!(cin >> n1 >> n2 >> n3 >> w1 >> w2 >> w3)) return 0;

    double arithmetic = (n1 + n2 + n3) / 3.0;
    double weighted = (n1 * w1 + n2 * w2 + n3 * w3) / (w1 + w2 + w3);
    double harmonic = 3.0 / ((1.0 / n1) + (1.0 / n2) + (1.0 / n3));

    cout << fixed << setprecision(1);
    cout << "a: " << arithmetic << "\n";
    cout << "p: " << weighted << "\n";
    cout << "h: " << harmonic << "\n";

    return 0;
}