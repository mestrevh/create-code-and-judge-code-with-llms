/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem: Terror na última volta
 * Formula 1 scoring system:
 * 1st: 25, 2nd: 18, 3rd: 15, 4th: 12, 5th: 10,
 * 6th: 8, 7th: 6, 8th: 4, 9th: 2, 10th: 1
 * 
 * Winner determined by total points.
 * Tie-breaker: Who finished ahead in more races.
 */

int get_points(int pos) {
    if (pos == 1) return 25;
    if (pos == 2) return 18;
    if (pos == 3) return 15;
    if (pos == 4) return 12;
    if (pos == 5) return 10;
    if (pos == 6) return 8;
    if (pos == 7) return 6;
    if (pos == 8) return 4;
    if (pos == 9) return 2;
    if (pos == 10) return 1;
    return 0;
}

int main() {
    // Standard I/O optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long scoreM, scoreL;
    int N;

    // Read initial scores and number of races
    if (!(cin >> scoreM >> scoreL >> N)) return 0;

    vector<string> m_ahead_races;
    vector<string> l_ahead_races;
    int m_ahead_count = 0;
    int l_ahead_count = 0;

    for (int i = 0; i < N; ++i) {
        string race_name;
        int posM, posL;
        cin >> race_name >> posM >> posL;

        // Add points based on position
        scoreM += get_points(posM);
        scoreL += get_points(posL);

        // Track who finished ahead in each race
        if (posM < posL) {
            m_ahead_count++;
            m_ahead_races.push_back(race_name);
        } else if (posL < posM) {
            l_ahead_count++;
            l_ahead_races.push_back(race_name);
        }
    }

    // Determine the winner
    bool marquinhosWins = false;
    if (scoreM > scoreL) {
        marquinhosWins = true;
    } else if (scoreL > scoreM) {
        marquinhosWins = false;
    } else {
        // Tie-breaker logic
        if (m_ahead_count > l_ahead_count) {
            marquinhosWins = true;
        } else {
            marquinhosWins = false;
        }
    }

    // Print result in the specified format
    if (marquinhosWins) {
        cout << "O vencedor e Marquinhos com " << (scoreM - scoreL) 
             << " pontos a mais, ficando a frente em ";
        for (const string& race : m_ahead_races) {
            cout << race << "/";
        }
        cout << endl;
    } else {
        cout << "O vencedor e Luis com " << (scoreL - scoreM) 
             << " pontos a mais, ficando a frente em ";
        for (const string& race : l_ahead_races) {
            cout << race << "/";
        }
        cout << endl;
    }

    return 0;
}