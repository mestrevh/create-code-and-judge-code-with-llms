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

    double earthWeight;
    const double gravities[] = {273.42, 3.78, 8.6, 9.8, 3.72, 24.8, 10.5, 8.5, 10.8, 5.88, 1.67};

    while (cin >> earthWeight) {
        for (int i = 0; i < 11; ++i) {
            double result = (earthWeight * gravities[i]) / 9.8;
            cout << fixed << setprecision(2) << result << "\n";
        }
    }

    return 0;
}