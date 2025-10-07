/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double temp, sum = 0;
    int count = 0;
    double minTemp = 0;

    while (cin >> temp) {
        if (temp < 0) {
            sum += temp;
            count++;
            if (temp < minTemp) {
                minTemp = temp;
            }
        }
    }

    cout << fixed << setprecision(2);
    if (count > 0) {
        cout << minTemp << endl;
        cout << sum / count << endl;
    } else {
        cout << "0.00\n0.00\n";
    }

    return 0;
}
