/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string flavor;
    int quantity;

    if (!(cin >> flavor >> quantity)) return 0;

    transform(flavor.begin(), flavor.end(), flavor.begin(), [](unsigned char c) {
        return tolower(c);
    });

    double price_per_ball;

    if (flavor == "morango" || flavor == "cereja") {
        price_per_ball = 4.50;
    } else if (flavor == "damasco" || flavor == "siriguela") {
        price_per_ball = 3.80;
    } else {
        price_per_ball = 2.75;
    }

    double total_price = price_per_ball * quantity;

    cout << fixed << setprecision(2) << total_price << "\n";
    if (quantity > 2) {
        cout << "COM CALDA" << endl;
    } else {
        cout << "SEM CALDA" << endl;
    }

    return 0;
}