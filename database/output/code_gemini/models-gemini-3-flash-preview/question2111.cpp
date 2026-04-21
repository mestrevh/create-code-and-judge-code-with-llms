/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double value;
    double sum = 0.0;
    int count = 0;

    while (cin >> value) {
        long long int_part = static_cast<long long>(value);
        if (value == static_cast<double>(int_part)) {
            if (int_part > 0 && int_part % 2 == 0) {
                sum += value;
                count++;
            }
        }
    }

    if (count == 0) {
        cout << -1 << endl;
    } else {
        double average = sum / count;
        cout << fixed << setprecision(2) << average << endl;
    }

    return 0;
}