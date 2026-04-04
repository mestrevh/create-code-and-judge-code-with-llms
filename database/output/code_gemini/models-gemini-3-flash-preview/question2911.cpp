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

    long long sum = 0;
    long long count = 0;
    long long value;

    while (cin >> value) {
        sum += value;
        count++;
    }

    if (count > 0) {
        double average = static_cast<double>(sum) / count;
        long long min_gon = (sum / 2) + 1;

        cout << fixed << setprecision(2) << average << "\n";
        cout << min_gon << "\n";
    }

    return 0;
}