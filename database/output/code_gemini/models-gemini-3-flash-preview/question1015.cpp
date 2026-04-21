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
    if (!(cin >> n)) return 0;

    vector<long double> vx(n), vy(n);
    long double sum_x = 0.0;
    long double sum_y = 0.0;

    for (int i = 0; i < n; ++i) {
        if (!(cin >> vx[i] >> vy[i])) break;
        sum_x += vx[i];
        sum_y += vy[i];
    }

    long double mean_x = sum_x / (long double)n;
    long double mean_y = sum_y / (long double)n;

    long double numerator = 0.0;
    long double denominator = 0.0;

    for (int i = 0; i < n; ++i) {
        long double diff_x = vx[i] - mean_x;
        long double diff_y = vy[i] - mean_y;
        numerator += diff_x * diff_y;
        denominator += diff_x * diff_x;
    }

    long double a = 0.0;
    if (denominator != 0) {
        a = numerator / denominator;
    }
    
    long double b = mean_y - a * mean_x;

    cout << fixed << setprecision(2);
    cout << "A: " << a << "\n";
    cout << "B: " << b << "\n";

    return 0;
}