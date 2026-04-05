/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> values;
    long long val;
    while (cin >> val) {
        values.push_back(val);
    }

    if (values.empty()) return 0;

    sort(values.begin(), values.end());

    int n = values.size();
    cout << "Mediana = ";
    if (n % 2 != 0) {
        cout << values[n / 2] << endl;
    } else {
        double median = (values[n / 2 - 1] + values[n / 2]) / 2.0;
        cout << fixed << setprecision(1) << median << endl;
    }

    return 0;
}