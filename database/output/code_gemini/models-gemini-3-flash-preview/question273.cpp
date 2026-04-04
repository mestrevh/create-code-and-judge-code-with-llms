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

    double A, B;
    if (cin >> A >> B) {
        double media = (A * 3.5 + B * 7.5) / 11.0;
        cout << fixed << setprecision(5) << "MEDIA = " << media << endl;
    }

    return 0;
}