/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string lowerStr(string s) {
    for (char &c : s) c = (char)tolower((unsigned char)c);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string name;
    while (true) {
        if (!(cin >> name)) return 0;
        if (lowerStr(name) == "fim") return 0;

        int n;
        if (!(cin >> n)) return 0;

        double total = 0.0;
        for (int i = 0; i < n; i++) {
            string media;
            cin >> media;
            media = lowerStr(media);

            if (media == "internet") total += 3000.0;
            else if (media == "revista") total += 750.0;
            else if (media == "outdoor") total += 1500.0;
            else if (media == "radio") {
                string band;
                cin >> band;
                band = lowerStr(band);
                if (band == "fm") total += 500.0;
                else total += 300.0;
            } else if (media == "tv") {
                double hour;
                cin >> hour;
                if (hour <= 20.0) total += 1200.0;
                else total += 2000.0;
            }
        }

        cout << name << ": " << fixed << setprecision(2) << total << "\n";
    }
    return 0;
}