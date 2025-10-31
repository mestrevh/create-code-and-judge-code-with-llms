/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> field(N, vector<int>(M, 0));
    string command;
    int total_collected = 0, total_insecticide = 0;

    while (cin >> command) {
        if (command == "Colher") {
            int collected = 0;
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    if (field[i][j] == 3) {
                        collected++;
                        field[i][j] = 0; 
                    }
            total_collected += collected;
        } else if (command == "Plantar") {
            int y;
            cin >> y;
            total_insecticide += y * 1 * 2; // 1 for each plant, 2ml each
            for (int i = 0; i < y; i++) {
                int row;
                cin >> row;
                for (int j = 0; j < M; j++)
                    if (field[row][j] == 0) field[row][j] = 1;
            }
        } else if (command == "Temporada") {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++) {
                    if (field[i][j] > 0 && field[i][j] < 3) field[i][j]++;
                }
        } else if (command == "Ataque") {
            int k, w;
            cin >> k >> w;
            if (field[k][w] == 1 || field[k][w] == 2) field[k][w] = -1;
        }
    }

    for (const auto& row : field) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
    cout << "Foram colhidos " << total_collected << " morangos." << endl;
    cout << "Foram utilizados " << total_insecticide << "ml de inseticida." << endl;

    return 0;
}
