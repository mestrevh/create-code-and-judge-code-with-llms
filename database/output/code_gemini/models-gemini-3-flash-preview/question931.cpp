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

    string candidate;
    while (cin >> candidate && candidate != "FIM") {
        int n;
        if (!(cin >> n)) break;

        double total_cost = 0.0;
        for (int i = 0; i < n; ++i) {
            string media;
            cin >> media;

            if (media == "internet") {
                total_cost += 3000.0;
            } else if (media == "revista") {
                total_cost += 750.0;
            } else if (media == "outdoor") {
                total_cost += 1500.0;
            } else if (media == "radio") {
                string subtype;
                cin >> subtype;
                if (subtype == "fm") {
                    total_cost += 500.0;
                } else if (subtype == "am") {
                    total_cost += 300.0;
                }
            } else if (media == "tv") {
                int hour;
                cin >> hour;
                if (hour <= 20) {
                    total_cost += 1200.0;
                } else {
                    total_cost += 2000.0;
                }
            }
        }

        cout << candidate << ": " << fixed << setprecision(2) << total_cost << "\n";
    }

    return 0;
}