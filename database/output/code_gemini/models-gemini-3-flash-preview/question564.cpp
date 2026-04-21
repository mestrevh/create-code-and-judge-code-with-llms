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

    double max_speed, car_speed;
    if (!(cin >> max_speed >> car_speed)) return 0;

    double fine = 0.00;
    int points = 0;

    if (car_speed > max_speed) {
        if (car_speed <= max_speed * 1.20) {
            fine = 85.13;
            points = 4;
        } else if (car_speed <= max_speed * 1.50) {
            fine = 127.69;
            points = 5;
        } else {
            fine = 574.62;
            points = 7;
        }
    }

    cout << fixed << setprecision(2) << fine << "\n";
    cout << points << "\n";

    return 0;
}