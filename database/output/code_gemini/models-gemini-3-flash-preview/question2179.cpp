/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<double> scores;
    for (int i = 0; i < 5; ++i) {
        string name;
        if (!getline(cin >> ws, name)) break;

        double d, g, c, e;
        if (!(cin >> d >> g >> c >> e)) break;

        int min_count = 0;
        if (d == 0) min_count++;
        if (g == 0) min_count++;
        if (c == 0) min_count++;
        if (e == 0) min_count++;

        double index = 0.0;
        if (min_count < 2) {
            index = (d * 2.0) + (g * 3.5) + (c * 1.5) + (e * 2.0);
        }
        scores.push_back(index);
    }

    sort(scores.begin(), scores.end(), greater<double>());

    cout << fixed << setprecision(1);
    for (int i = 0; i < 3 && i < (int)scores.size(); ++i) {
        cout << scores[i] << "\n";
    }

    return 0;
}