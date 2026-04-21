/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char op;
    double maxSpeed = -1.0;
    int maxYear = -1;
    double sumSpeed = 0.0;
    int count = 0;

    while (cin >> op && (op != 'n' && op != 'N')) {
        int year;
        double speed;
        if (!(cin >> year >> speed)) break;
        
        if (count == 0) {
            maxSpeed = speed;
            maxYear = year;
        } else {
            if (speed > maxSpeed) maxSpeed = speed;
            if (year > maxYear) maxYear = year;
        }
        
        sumSpeed += speed;
        count++;
    }

    if (count == 0) {
        cout << "zero" << endl;
    } else {
        cout << fixed << setprecision(2) << maxSpeed << "\n";
        cout << maxYear << "\n";
        cout << fixed << setprecision(2) << (sumSpeed / (double)count) << endl;
    }

    return 0;
}