/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string names[5];
    int ages[5];
    int sum_ages = 0;
    double product_ages = 1.0;

    for (int i = 0; i < 5; ++i) {
        string name;
        getline(cin >> ws, name);
        names[i] = name;

        double raw_age;
        if (cin >> raw_age) {
            // Requirement: handle negative (fabs) and convert decimal to int
            ages[i] = (int)fabs(raw_age);
            sum_ages += ages[i];
            product_ages *= ages[i];
        }
    }

    // Task a) Output Names and Ages
    for (int i = 0; i < 5; ++i) {
        cout << "Pessoa: " << names[i] << " , " << ages[i] << "\n";
    }

    // Task b) Output Sum
    cout << sum_ages << "\n";

    // Task c) Output Arithmetic Mean
    double arithmetic_mean = (double)sum_ages / 5.0;
    cout << arithmetic_mean << "\n";

    // Task c) Output Truncated Geometric Mean
    double geometric_mean = pow(product_ages, 1.0 / 5.0);
    // Truncate to int as requested
    cout << (int)geometric_mean << "\n";

    return 0;
}