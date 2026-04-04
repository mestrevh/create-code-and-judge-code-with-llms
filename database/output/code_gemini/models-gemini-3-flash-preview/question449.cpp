/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string food, drink;
    if (!(cin >> food >> drink)) return 0;

    for (char &c : food) c = tolower((unsigned char)c);
    for (char &c : drink) c = tolower((unsigned char)c);

    double total = 0.0;

    if (food == "lasanha") {
        total += 8.00;
    } else if (food == "estrogonofe") {
        total += 11.00;
    }

    if (drink == "refrigerante") {
        total += 3.00;
    } else if (drink == "suco") {
        total += 2.50;
    }

    cout << fixed << setprecision(2) << total << endl;

    return 0;
}