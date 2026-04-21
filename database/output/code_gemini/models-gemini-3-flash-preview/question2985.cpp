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

    double distance, liters;
    if (cin >> distance >> liters) {
        if (liters != 0) {
            double consumption = distance / liters;
            cout << fixed << setprecision(1) << consumption << endl;
        }
    }

    return 0;
}