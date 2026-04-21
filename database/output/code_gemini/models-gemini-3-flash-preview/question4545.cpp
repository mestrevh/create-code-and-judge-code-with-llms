/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n < 2) {
        double dummy;
        for (int i = 0; i < n; ++i) cin >> dummy;
        cin >> dummy;
        cout << "NAO" << endl;
        return 0;
    }

    vector<double> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    double s;
    cin >> s;

    sort(a.begin(), a.end());

    int i = 0;
    int j = n - 1;
    bool found = false;
    const double EPS = 1e-9;

    while (i < j) {
        double current_sum = a[i] + a[j];
        if (abs(current_sum - s) < EPS) {
            found = true;
            break;
        } else if (current_sum < s) {
            i++;
        } else {
            j--;
        }
    }

    if (found) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }

    return 0;
}