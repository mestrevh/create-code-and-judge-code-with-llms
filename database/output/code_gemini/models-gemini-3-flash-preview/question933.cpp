/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        if (n <= 0) continue;

        vector<double> notes(n);
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> notes[i];
            sum += notes[i];
        }

        double average = sum / static_cast<double>(n);
        double closest_note = notes[0];
        double min_diff = abs(notes[0] - average);

        for (int i = 1; i < n; ++i) {
            double current_diff = abs(notes[i] - average);
            if (current_diff < min_diff) {
                min_diff = current_diff;
                closest_note = notes[i];
            }
        }

        cout << fixed << setprecision(2);
        cout << "MEDIA: " << average << "\n";
        cout << "MAIS PROXIMO: " << closest_note << "\n";
        cout << "DIFERENCA: " << abs(closest_note - average) << "\n";
    }

    return 0;
}