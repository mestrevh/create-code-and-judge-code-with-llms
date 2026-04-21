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

    double A, B, C;
    if (cin >> A >> B >> C) {
        double result = (A * 2.0 + B * 3.0 + C * 5.0) / 10.0;
        cout << fixed << setprecision(1) << "MEDIA = " << result << endl;
    }

    return 0;
}