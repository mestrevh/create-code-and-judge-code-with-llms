/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int num_teams = 1 << n;
    vector<pair<int, int>> schedules(num_teams);
    for (int i = 0; i < num_teams; ++i) {
        cin >> schedules[i].first >> schedules[i].second;
    }

    long long min_cost = -1;

    for (int i = 0; i < (1 << (2 * num_teams)); ++i) {
        long long current_cost = 0;
        vector<pair<int, int>> current_schedules = schedules;

        for (int j = 0; j < 2 * num_teams; ++j) {
            if ((i >> j) & 1) {
                int team_index = j / 2;
                int side = j % 2; 

                if (side == 0) {
                    current_cost += abs(schedules[team_index].first - (schedules[team_index].first + 1));
                    current_schedules[team_index].first++;
                 } else {
                    current_cost += abs(schedules[team_index].second - (schedules[team_index].second -1));
                    current_schedules[team_index].second--;
                }
            }
        }
        
        bool possible = true;
        for (int round = 0; round < n; ++round) {
            for (int k = 0; k < (1 << (n - round)); k += 2) {
                int team1 = k;
                int team2 = k + 1;
                if (max(current_schedules[team1].first, current_schedules[team2].first) > min(current_schedules[team1].second, current_schedules[team2].second)) {
                    possible = false;
                    break;
                }
            }
            if (!possible) break;
             vector<pair<int, int>> next_round_schedules;
            for (int k = 0; k < (1 << (n - round)); k+=2) {
              next_round_schedules.push_back(current_schedules[k]);
            }
             current_schedules = next_round_schedules;


        }

        if (possible) {
            if (min_cost == -1 || current_cost < min_cost) {
                min_cost = current_cost;
            }
        }
    }

    cout << min_cost << endl;

    return 0;
}
