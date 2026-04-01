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

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    if (n <= 0) {
        cout << "S: 0.00" << endl;
        return 0;
    }

    double s = 0.0;
    double num_odd = 1.0;
    double den_odd = 1.0;
    double num_even = 2.0;
    double den_even = 3.0;

    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) {
            s += num_odd / den_odd;
            num_odd += 2.0;
            den_odd *= 4.0;
        } else {
            s += num_even / den_even;
            num_even *= 4.0;
            den_even += 3.0;
        }
    }

    cout << "S: " << fixed << setprecision(2) << s << endl;

    return 0;
}