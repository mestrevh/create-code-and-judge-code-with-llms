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

    int X;
    double Y;

    if (cin >> X >> Y) {
        double consumption = static_cast<double>(X) / Y;
        cout << fixed << setprecision(3) << consumption << " km/l" << endl;
    }

    return 0;
}