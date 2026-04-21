/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Clue {
    int x, y, d;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<Clue> clues(K);
    for (int i = 0; i < K; ++i) {
        cin >> clues[i].x >> clues[i].y >> clues[i].d;
    }

    int foundX = -1, foundY = -1;
    int possibleCount = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bool valid = true;
            for (int k = 0; k < K; ++k) {
                int dist = abs(i - clues[k].x) + abs(j - clues[k].y);
                if (dist != clues[k].d) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                possibleCount++;
                foundX = i;
                foundY = j;
                if (possibleCount > 1) {
                    cout << "-1 -1" << endl;
                    return 0;
                }
            }
        }
    }

    if (possibleCount == 1) {
        cout << foundX << " " << foundY << endl;
    } else {
        cout << "-1 -1" << endl;
    }

    return 0;
}