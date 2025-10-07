/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct Team {
    std::string name;
    int points = 0;
    int wins = 0;
    int draws = 0;
    int losses = 0;
    int goals_for = 0;
    int goals_against = 0;
    int goal_difference = 0;
};

bool compareTeams(const Team& a, const Team& b) {
    if (a.points != b.points) {
        return a.points > b.points;
    }
    if (a.wins != b.wins) {
        return a.wins > b.wins;
    }
    if (a.goal_difference != b.goal_difference) {
        return a.goal_difference > b.goal_difference;
    }
    if (a.goals_for != b.goals_for) {
        return a.goals_for > b.goals_for;
    }
    return a.name < b.name;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::map<std::string, Team> stats;

    for (int i = 0; i < n; ++i) {
        std::string home_team_name, away_team_name, x_char;
        int home_goals, away_goals;

        std::cin >> home_team_name >> home_goals >> x_char >> away_goals >> away_team_name;

        stats[home_team_name].name = home_team_name;
        stats[away_team_name].name = away_team_name;

        stats[home_team_name].goals_for += home_goals;
        stats[home_team_name].goals_against += away_goals;
        stats[away_team_name].goals_for += away_goals;
        stats[away_team_name].goals_against += home_goals;

        if (home_goals > away_goals) {
            stats[home_team_name].points += 3;
            stats[home_team_name].wins += 1;
            stats[away_team_name].losses += 1;
        } else if (away_goals > home_goals) {
            stats[away_team_name].points += 3;
            stats[away_team_name].wins += 1;
            stats[home_team_name].losses += 1;
        } else {
            stats[home_team_name].points += 1;
            stats[home_team_name].draws += 1;
            stats[away_team_name].points += 1;
            stats[away_team_name].draws += 1;
        }
    }

    std::vector<Team> table;
    for (auto const& pair : stats) {
        table.push_back(pair.second);
    }

    for (auto& team : table) {
        team.goal_difference = team.goals_for - team.goals_against;
    }

    std::sort(table.begin(), table.end(), compareTeams);

    for (size_t i = 0; i < table.size(); ++i) {
        std::cout << i + 1 << ". " << table[i].name << " "
                  << table[i].points << " "
                  << table[i].wins << " "
                  << table[i].draws << " "
                  << table[i].losses << " "
                  << table[i].goals_for << " "
                  << table[i].goals_against << " "
                  << table[i].goal_difference << "\n";
    }

    return 0;
}
