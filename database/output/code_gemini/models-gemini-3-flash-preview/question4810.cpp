/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    int good_count = 0;
    double max_score = -1.0;
    string best_place = "";

    for (int i = 0; i < N; ++i) {
        string name;
        double p, g, t;
        if (!(cin >> name >> p >> g >> t)) break;

        // Formula: (3 * P + G + 2 * T) / 6
        double score = (3.0 * p + g + 2.0 * t) / 6.0;

        // Check if the place is "good" (nota final >= 3.5)
        // Using a small epsilon to handle precision issues
        if (score >= 3.5 - 1e-9) {
            good_count++;
            
            // Track the place with the highest score. 
            // In case of a tie, the one that entered first is kept.
            if (score > max_score + 1e-9) {
                max_score = score;
                best_place = name;
            }
        }
    }

    if (good_count == 0) {
        cout << "Puts. Melhor ficar em casa mesmo" << endl;
    } else {
        cout << "Temos " << good_count << " lugares pra visitar!" << endl;
        // Using "comecar" as per the sample output formatting
        cout << "Devo comecar por " << best_place << endl;
    }

    return 0;
}