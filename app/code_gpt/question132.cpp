/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int N, M, S;
    while (cin >> N >> M >> S, N || M || S) {
        vector<string> arena(N);
        pair<int, int> pos;
        char direction;
        for (int i = 0; i < N; i++) {
            cin >> arena[i];
            for (int j = 0; j < M; j++) {
                if (arena[i][j] == 'N' || arena[i][j] == 'S' || arena[i][j] == 'L' || arena[i][j] == 'O') {
                    pos = {i, j};
                    direction = arena[i][j];
                    arena[i][j] = '.';
                }
            }
        }

        map<char, pair<int, int>> dir_map = {
            {'N', {-1, 0}}, {'S', {1, 0}}, {'L', {0, 1}}, {'O', {0, -1}}
        };
        char directions[] = {'N', 'L', 'S', 'O'};
        int dir_index = (direction == 'N') ? 0 : (direction == 'L') ? 1 : (direction == 'S') ? 2 : 3;

        int collected = 0;
        string instructions;
        cin >> instructions;
        
        for (char inst : instructions) {
            if (inst == 'D') {
                dir_index = (dir_index + 1) % 4;
            } else if (inst == 'E') {
                dir_index = (dir_index + 3) % 4;
            } else if (inst == 'F') {
                int new_x = pos.first + dir_map[directions[dir_index]].first;
                int new_y = pos.second + dir_map[directions[dir_index]].second;
                
                if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && arena[new_x][new_y] != '#') {
                    pos = {new_x, new_y};
                    if (arena[new_x][new_y] == '*') {
                        collected++;
                        arena[new_x][new_y] = '.';
                    }
                }
            }
        }

        cout << collected << endl;
    }
    return 0;
}
