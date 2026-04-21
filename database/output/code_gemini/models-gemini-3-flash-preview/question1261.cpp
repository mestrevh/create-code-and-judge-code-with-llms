/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    if (N < 0) return 0;

    vector<pair<string, string>> matchups(N);
    for (int i = 0; i < N; ++i) {
        string matchup_str;
        cin >> matchup_str;
        size_t x_pos = matchup_str.find('x');
        if (x_pos != string::npos) {
            matchups[i].first = matchup_str.substr(0, x_pos);
            matchups[i].second = matchup_str.substr(x_pos + 1);
        }
    }

    map<string, int> win_counts;
    win_counts["Gryffindor"] = 0;
    win_counts["Slytherin"] = 0;
    win_counts["Hufflepuff"] = 0;
    win_counts["Ravenclaw"] = 0;

    for (int i = 0; i < N; ++i) {
        string score_str;
        cin >> score_str;
        size_t dash_pos = score_str.find('-');
        if (dash_pos != string::npos) {
            int p1 = stoi(score_str.substr(0, dash_pos));
            int p2 = stoi(score_str.substr(dash_pos + 1));
            
            if (p1 > p2) {
                if (win_counts.count(matchups[i].first)) {
                    win_counts[matchups[i].first]++;
                }
            } else if (p2 > p1) {
                if (win_counts.count(matchups[i].second)) {
                    win_counts[matchups[i].second]++;
                }
            }
        }
    }

    int max_wins = 0;
    string houses[] = {"Gryffindor", "Slytherin", "Hufflepuff", "Ravenclaw"};
    
    for (int i = 0; i < 4; ++i) {
        if (win_counts[houses[i]] > max_wins) {
            max_wins = win_counts[houses[i]];
        }
    }

    if (max_wins == 0) {
        for (int i = 0; i < 4; ++i) {
            cout << houses[i] << "\n";
        }
    } else {
        for (int i = 0; i < 4; ++i) {
            if (win_counts[houses[i]] == max_wins) {
                cout << houses[i] << "\n";
            }
        }
    }

    return 0;
}