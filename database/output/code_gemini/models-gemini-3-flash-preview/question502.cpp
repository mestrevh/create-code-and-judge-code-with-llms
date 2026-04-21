/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double total_revenue = 0.0;
    int radio_count = 0;
    int tv_count = 0;
    int magazine_count = 0;
    int outdoor_count = 0;

    string media_type;
    for (int i = 0; i < 7; ++i) {
        if (!(cin >> media_type)) break;

        if (media_type == "Rádio") {
            radio_count++;
            string band;
            cin >> band;
            if (band == "AM") {
                total_revenue += 300.0;
            } else {
                total_revenue += 500.0;
            }
        } else if (media_type == "TV") {
            tv_count++;
            int hour;
            cin >> hour;
            if (hour <= 20) {
                total_revenue += 1200.0;
            } else {
                total_revenue += 2000.0;
            }
        } else if (media_type == "Revista") {
            magazine_count++;
            total_revenue += 750.0;
        } else if (media_type == "Outdoor") {
            outdoor_count++;
            total_revenue += 1500.0;
        }
    }

    cout << fixed << setprecision(2) << total_revenue << "\n";
    cout << radio_count << "\n";
    cout << tv_count << "\n";
    cout << magazine_count << "\n";
    cout << outdoor_count << "\n";

    return 0;
}