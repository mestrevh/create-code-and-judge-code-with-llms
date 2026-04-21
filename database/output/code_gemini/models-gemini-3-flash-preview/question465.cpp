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

    double value;
    double sum = 0.0;
    int count = 0;

    while (cin >> value && value >= 0) {
        sum += value;
        count++;
    }

    double average = 0.0;
    if (count > 0) {
        average = sum / count;
    }

    cout << fixed << setprecision(2) << sum << "\n";
    cout << fixed << setprecision(2) << average << "\n";

    return 0;
}