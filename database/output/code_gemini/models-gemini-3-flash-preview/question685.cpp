/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> board(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    int max_food = 0;
    int current_food = 0;

    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == 'o') {
                    current_food++;
                    if (current_food > max_food) max_food = current_food;
                } else if (board[i][j] == 'A') {
                    current_food = 0;
                }
            }
        } else {
            for (int j = N - 1; j >= 0; --j) {
                if (board[i][j] == 'o') {
                    current_food++;
                    if (current_food > max_food) max_food = current_food;
                } else if (board[i][j] == 'A') {
                    current_food = 0;
                }
            }
        }
    }

    cout << max_food << endl;

    return 0;
}