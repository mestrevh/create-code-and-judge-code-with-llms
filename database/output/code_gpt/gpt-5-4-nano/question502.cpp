/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string media;
    double total = 0.0;
    int countRadio = 0, countTV = 0, countRevista = 0, countOutdoor = 0;

    for (int i = 0; i < 7; i++) {
        if (!getline(cin, media)) break;
        while (media.size() == 0 && cin) getline(cin, media);
        if (!cin && media.size() == 0) break;

        if (media == "Rádio") {
            string faixa;
            getline(cin, faixa);
            while (faixa.size() == 0 && cin) getline(cin, faixa);
            if (faixa == "AM") total += 300.0;
            else total += 500.0;
            countRadio++;
        } else if (media == "TV") {
            string line;
            getline(cin, line);
            while (line.size() == 0 && cin) getline(cin, line);
            int h = stoi(line);
            if (h <= 20) total += 1200.0;
            else total += 2000.0;
            countTV++;
        } else if (media == "Revista") {
            total += 750.0;
            countRevista++;
        } else if (media == "Outdoor") {
            total += 1500.0;
            countOutdoor++;
        }
    }

    cout << fixed << setprecision(2) << total << "\n";
    cout << countRadio << "\n";
    cout << countTV << "\n";
    cout << countRevista << "\n";
    cout << countOutdoor << "\n";
    return 0;
}