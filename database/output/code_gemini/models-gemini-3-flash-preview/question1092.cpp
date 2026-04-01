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

    int count_m = 0;
    int count_f = 0;
    double sum_total = 0.0;
    double sum_m = 0.0;
    double max_sal = -1.0;
    char sex_max = ' ';

    for (int i = 0; i < 10; ++i) {
        double sal;
        char s;
        if (!(cin >> sal >> s)) break;

        if (sal > max_sal) {
            max_sal = sal;
            sex_max = s;
        }

        if (s == 'm' || s == 'M') {
            count_m++;
            sum_m += sal;
        } else if (s == 'f' || s == 'F') {
            count_f++;
        }
        sum_total += sal;
    }

    cout << count_m << "\n";
    cout << count_f << "\n";
    cout << fixed << setprecision(1) << (sum_total / 10.0) << "\n";
    cout << sex_max << "\n";
    if (count_m > 0) {
        cout << fixed << setprecision(1) << (sum_m / (double)count_m) << "\n";
    } else {
        cout << fixed << setprecision(1) << 0.0 << "\n";
    }

    return 0;
}