/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int color;
    string line;

    if (!(cin >> color)) return 0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, line);

    long long letters = (long long)line.size();

    double price = 0.0;

    if (color == 1) {
        if (letters >= 1 && letters <= 10) price = 0.75 * letters;
        else if (letters <= 30) price = 0.45 * letters;
        else price = 0.20 * letters;
        price += 2.0;
    } else {
        if (letters >= 1 && letters <= 10) price = 0.25 * letters;
        else if (letters <= 30) price = 0.15 * letters;
        else price = 0.10 * letters;
        price += 6.0;
    }

    double bestPrice;
    int bestGraph;

    auto compute = [&](int g)->double{
        double base = (g == 1 ? 2.0 : 6.0);
        double per = 0.0;
        if (letters >= 1 && letters <= 10) per = (g == 1 ? 0.75 : 0.25);
        else if (letters <= 30) per = (g == 1 ? 0.45 : 0.15);
        else per = (g == 1 ? 0.20 : 0.10);
        return base + per * letters;
    };

    double p1 = compute(1);
    double p2 = compute(2);

    if (p1 <= p2) {
        bestGraph = 1;
        bestPrice = p1;
    } else {
        bestGraph = 2;
        bestPrice = p2;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    cout << "A grafica " << bestGraph << " eh a mais em conta\n";
    cout << "O preco sera: $" << bestPrice << "\n";
    return 0;
}