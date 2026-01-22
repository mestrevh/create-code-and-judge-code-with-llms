/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int life;
    cin >> life;

    vector<vector<string>> map(5, vector<string>(5));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> map[i][j];

    int directions_count;
    cin >> directions_count;

    vector<string> directions(directions_count);
    for (int i = 0; i < directions_count; i++)
        cin >> directions[i];

    int player_x, player_y;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (map[i][j] == "@") {
                player_x = i;
                player_y = j;
            }

    for (const auto& dir : directions) {
        int new_x = player_x, new_y = player_y;

        if (dir == "D") new_y++;
        else if (dir == "E") new_y--;
        else if (dir == "C") new_x--;

        if (new_x < 0 || new_x >= 5 || new_y < 0 || new_y >= 5 || map[new_x][new_y] == "#") {
            cout << "Uma magic wall aqui? druid desgraçado" << endl;
            continue;
        }

        if (map[new_x][new_y] == "$") {
            map[player_x][player_y] = "*";
            player_x = new_x;
            player_y = new_y;
            break;
        }

        if (isdigit(map[new_x][new_y][0])) {
            int dragon_strength = stoi(map[new_x][new_y]);
            if (life > dragon_strength) {
                life -= dragon_strength;
                cout << "Minha Royal Spear deita qualquer Dragon" << endl;
                map[player_x][player_y] = "*";
                player_x = new_x;
                player_y = new_y;
            } else {
                cout << "Minhas HPs acabaram, esse Frost Dragon me deitou" << endl;
                life = 0;
                break;
            }
        } else {
            map[player_x][player_y] = "*";
            player_x = new_x;
            player_y = new_y;
        }
    }

    for (const auto& row : map) {
        for (const auto& cell : row)
            cout << cell << " ";
        cout << endl;
    }

    cout << (map[player_x][player_y] == "$" ? "Finalmente acabei a quest" : "Quem foi o newba que escreveu essas coordenadas") << endl;

    return 0;
}
