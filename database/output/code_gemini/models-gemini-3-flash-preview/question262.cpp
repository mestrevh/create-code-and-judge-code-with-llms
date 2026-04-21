/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    if (n <= 0) {
        return 0;
    }

    vector<double> notes(n);
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        if (cin >> notes[i]) {
            sum += notes[i];
        }
    }

    double average = sum / (double)n;
    
    // As per problem description and confirmed by test cases:
    // "mais de 10% acima da média" -> value > average * 1.1
    // "menos de 10% abaixo da média" -> value < average * 0.9
    double upper_threshold = average * 1.1;
    double lower_threshold = average * 0.9;

    int count_above = 0;
    int count_below = 0;

    // Use a small epsilon for floating point comparison robustness
    const double eps = 1e-9;

    for (int i = 0; i < n; ++i) {
        if (notes[i] > upper_threshold + eps) {
            count_above++;
        }
        if (notes[i] < lower_threshold - eps) {
            count_below++;
        }
    }

    cout << fixed << setprecision(2) << average << "\n";
    cout << count_above << "\n";
    cout << count_below << "\n";

    return 0;
}