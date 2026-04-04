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

    double a, b, c;
    if (cin >> a >> b >> c) {
        double sum_of_squares = (a * a) + (b * b) + (c * c);
        double square_of_sum = (a + b + c) * (a + b + c);

        cout << fixed << setprecision(1) << sum_of_squares << "\n";
        cout << fixed << setprecision(1) << square_of_sum << "\n";
    }

    return 0;
}
