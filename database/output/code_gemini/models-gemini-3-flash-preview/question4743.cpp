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

    int celsius;
    if (!(cin >> celsius)) return 0;

    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

    cout << fixed << setprecision(1) << fahrenheit << endl;

    return 0;
}