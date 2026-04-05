/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    if (!(cin >> c)) return 0;

    double maxSpeed = -1e100;
    int maxYear = numeric_limits<int>::min();
    double sumSpeed = 0.0;
    long long cnt = 0;

    while (c != 'n' && c != 'N') {
        int year;
        double speed;
        if (!(cin >> year >> speed)) break;

        if (speed > maxSpeed) maxSpeed = speed;
        if (year > maxYear) maxYear = year;
        sumSpeed += speed;
        cnt++;

        if (!(cin >> c)) break;
    }

    if (cnt == 0) {
        cout << "zero\n";
        return 0;
    }

    cout.setf(ios::fixed);
    cout << setprecision(2) << maxSpeed << "\n";
    cout << maxYear << "\n";
    cout << setprecision(2) << (sumSpeed / cnt) << "\n";
    return 0;
}