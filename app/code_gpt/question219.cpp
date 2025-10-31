/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
bool hole[8][8] = {{false}};
int startX = 4, startY = 3;

int main() {
    int N;
    cin >> N;
    vector<int> sequence(N);
    for(int i = 0; i < N; i++) {
        cin >> sequence[i];
    }
    
    hole[1][3] = hole[2][3] = hole[2][5] = hole[5][4] = true;
    int x = startX, y = startY, count = 0;

    for(int i = 0; i < N; i++) {
        int moveIndex = sequence[i] - 1;
        x += moves[moveIndex][0];
        y += moves[moveIndex][1];
        count++;
        if (x < 0 || x >= 8 || y < 0 || y >= 8 || hole[x][y]) {
            break;
        }
    }
    
    cout << count << endl;
    return 0;
}
