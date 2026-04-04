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

    int n;
    double totalFine = 0.0;
    int finedHouses = 0;

    while (cin >> n && n != 999) {
        if (n > 2) {
            totalFine += (n - 2) * 12.89;
            finedHouses++;
        }
    }

    cout << fixed << setprecision(2) << totalFine << "\n";
    cout << finedHouses << "\n";

    return 0;
}