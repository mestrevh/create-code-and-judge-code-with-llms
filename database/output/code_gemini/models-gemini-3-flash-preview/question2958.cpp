/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c, d;
    if (cin >> a >> b >> c >> d) {
        double media = (a + b + c + d) / 4.0;
        cout << "A media das alturas eh: " << media << endl;
    }

    return 0;
}