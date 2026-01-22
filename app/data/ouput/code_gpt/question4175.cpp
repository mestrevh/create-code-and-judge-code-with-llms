/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    int d1 = stoi(input.substr(0, 2));
    int m1 = stoi(input.substr(3, 2));
    int d2 = stoi(input.substr(10, 2));
    int m2 = stoi(input.substr(13, 2));

    int T;
    cin >> T;
    float lat1, long1;
    cin >> lat1 >> long1;

    int daysPassed = (m2 - m1) * 30 + (d2 - d1);
    int nextMurderDay = daysPassed / T + 1;
    int nextDay = d1 + nextMurderDay * T;

    int nextMonth = m1 + (nextDay - 1) / 30;
    nextDay = (nextDay - 1) % 30 + 1;

    if (nextMonth > 12) {
        nextMonth = nextMonth - 12;
    }

    float nextLat = lat1 + T * cos(daysPassed * M_PI / 180);
    float nextLong = long1 + T * sin(daysPassed * M_PI / 180);

    cout << "o proximo assassinato sera dia " << setw(2) << setfill('0') << nextDay << "/" << setw(2) << setfill('0') << nextMonth << endl;
    cout << "As coordenadas sao lat = " << fixed << setprecision(2) << nextLat << "°, long = " << nextLong << "°" << endl;

    return 0;
}
