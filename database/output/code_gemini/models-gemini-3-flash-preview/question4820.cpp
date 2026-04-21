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

struct Enemy {
    int amp;
    int freq;
    double energy;
    bool periodic;
    int e_score;
    bool defeated_by_princess;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p_amp, p_freq;
    double p_energy;
    string p_periodic_str;

    if (!(cin >> p_amp >> p_freq >> p_energy >> p_periodic_str)) return 0;
    bool p_periodic = (p_periodic_str == "TRUE");

    vector<Enemy> enemies;
    int max_p_score = 0;
    bool princess_won_any = false;

    int e_amp, e_freq;
    double e_energy;
    string e_periodic_str;

    while (cin >> e_amp >> e_freq >> e_energy >> e_periodic_str) {
        bool e_periodic = (e_periodic_str == "TRUE");
        int ps = 0;
        int es = 0;

        // Amplitude Comparison
        if (p_amp > e_amp) ps++;
        else if (e_amp > p_amp) es++;

        // Frequency Comparison
        if (e_freq != 0 && p_freq % e_freq == 0) ps++;
        if (p_freq != 0 && e_freq % p_freq == 0) es++;

        // Energy Comparison
        if (p_energy > e_energy) ps++;
        else if (e_energy > p_energy) es++;

        // Periodicity Comparison
        if (p_periodic && !e_periodic) ps++;
        else if (!p_periodic && e_periodic) es++;

        if (ps > max_p_score) max_p_score = ps;
        
        bool p_wins = (ps > es);
        if (p_wins) princess_won_any = true;

        enemies.push_back({e_amp, e_freq, e_energy, e_periodic, es, p_wins});
    }

    // Sort enemies by their score in descending order
    // Using stable_sort to preserve original input order for ties
    stable_sort(enemies.begin(), enemies.end(), [](const Enemy& a, const Enemy& b) {
        return a.e_score > b.e_score;
    });

    // Princess signal output
    cout << p_amp << " " << p_freq << " " << fixed << setprecision(2) << p_energy << " " << max_p_score;
    if (princess_won_any) {
        cout << " WINNER (";
        for (int i = 0; i < (int)enemies.size(); ++i) {
            if (enemies[i].defeated_by_princess) {
                cout << " " << i + 1;
            }
        }
        cout << " )";
    }
    cout << "\n---\n";

    // Enemy signals output
    bool flawless = (!enemies.empty());
    for (const auto& e : enemies) {
        cout << e.amp << " " << e.freq << " " << fixed << setprecision(2) << e.energy << " " << e.e_score;
        if (!e.defeated_by_princess) {
            cout << " WINNER";
            flawless = false;
        }
        cout << "\n";
    }

    // Final victory condition
    if (flawless) {
        cout << "FLAWLESS VICTORY!\n";
    }

    return 0;
}