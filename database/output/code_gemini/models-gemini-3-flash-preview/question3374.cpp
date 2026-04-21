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

    double a, b, c;
    if (cin >> a >> b >> c) {
        double average = (a + b + c) / 3.0;
        cout << fixed << setprecision(6) << average << endl;
    }

    return 0;
}