/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<double> numbers;
    double val;
    
    while (cin >> val) {
        if (val == -1.0) break;
        numbers.push_back(val);
    }

    if (numbers.empty()) return 0;

    int n = static_cast<int>(numbers.size());
    double sum = 0;
    for (double x : numbers) {
        sum += x;
    }
    
    double mean = sum / n;

    double variance_sum = 0;
    for (double x : numbers) {
        variance_sum += (x - mean) * (x - mean);
    }

    double standard_deviation = 0;
    if (n > 1) {
        standard_deviation = sqrt(variance_sum / (n - 1));
    }

    int count_greater = 0;
    for (double x : numbers) {
        if (x > mean) {
            count_greater++;
        }
    }

    cout << fixed << setprecision(2) << mean << "\n";
    cout << fixed << setprecision(2) << standard_deviation << "\n";
    cout << count_greater << "\n";

    return 0;
}