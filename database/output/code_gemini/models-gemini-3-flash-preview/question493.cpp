/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double temp;
    double min_temp = 0.0;
    double sum_negatives = 0.0;
    int count_negatives = 0;

    while (cin >> temp) {
        if (temp < min_temp) {
            min_temp = temp;
        }
        if (temp < 0) {
            sum_negatives += temp;
            count_negatives++;
        }
    }

    double avg_negatives = (count_negatives > 0) ? (sum_negatives / count_negatives) : 0.0;

    cout << fixed << setprecision(2);
    cout << min_temp << "\n";
    cout << avg_negatives << endl;

    return 0;
}