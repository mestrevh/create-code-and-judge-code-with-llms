/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

struct Competitor {
    string name;
    vector<pair<string, int>> path;
    bool fell_in_black_hole = false;
};

int main() {
    vector<Competitor> competitors(3);
    competitors[0].name = "Mario";
    competitors[1].name = "Yoshi";
    competitors[2].name = "Toad";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            string curve;
            int dist;
            cin >> curve >> dist;
            competitors[i].path.push_back({curve, dist});
           
            if (j > 1 && competitors[i].path[j - 1].first == "Esquerda" && 
                competitors[i].path[j - 2].first == "Esquerda" && 
                curve == "Esquerda") {
                competitors[i].fell_in_black_hole = true;
            }
        }
    }

    int min_distance = INT_MAX;
    string winner;

    for (const auto &competitor : competitors) {
        int total_distance = 0;
        for (const auto &curve : competitor.path) {
            total_distance += curve.second;
        }

        if (competitor.fell_in_black_hole) {
            cout << competitor.name << " caiu em um buraco negro." << endl;
        } else if (total_distance < min_distance) {
            min_distance = total_distance;
            winner = competitor.name;
        }
    }

    cout << winner << " venceu a corrida!" << endl;

    return 0;
}
