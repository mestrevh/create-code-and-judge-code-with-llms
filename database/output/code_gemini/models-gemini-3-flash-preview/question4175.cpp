/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line)) return 0;

    int d1, m1, d2, m2;
    if (sscanf(line.c_str(), "%d/%d - %d/%d", &d1, &m1, &d2, &m2) != 4) return 0;

    double T, lat0, lon0;
    if (!(cin >> T >> lat0 >> lon0)) return 0;

    // Convert dates to total days from the start of the year (30 days per month)
    double start_day = (m1 - 1) * 30.0 + (double)d1;
    double today_day = (m2 - 1) * 30.0 + (double)d2;

    // Find the index k of the first murder that happens on or after today_day
    int k = 0;
    while ((start_day + (double)k * T) < (today_day - 1e-9)) {
        k++;
    }

    // Calculate coordinates for the k-th murder
    // The k-th murder is calculated based on the previous (k-1) murders
    double current_lat = lat0;
    double current_lon = lon0;
    for (int i = 0; i < k; ++i) {
        double murder_day = start_day + (double)i * T;
        // The "day" used in cos/sin is the day of the month (1 to 30)
        double dom = fmod(murder_day - 1.0, 30.0) + 1.0;
        current_lat += T * cos(dom);
        current_lon += T * sin(dom);
    }

    // Determine the date of the next murder
    double next_day = start_day + (double)k * T;
    int next_day_int = (int)round(next_day);
    int next_m = (next_day_int - 1) / 30 + 1;
    int next_d = (next_day_int - 1) % 30 + 1;

    // Formatting the output according to the problem requirements
    cout << "o proximo assassinato sera dia " << setfill('0') << setw(2) << next_d << "/" << setfill('0') << setw(2) << next_m << "\n";
    cout << "As coordenadas sao lat = " << fixed << setprecision(2) << current_lat << "°, long = " << current_lon << "°\n";

    return 0;
}