/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long P;
    if (!(cin >> P)) return 0;

    int X;
    if (!(cin >> X)) return 0;

    vector<long long> arrayJ(X);
    long long sumJ = 0;
    for (int i = 0; i < X; ++i) {
        if (!(cin >> arrayJ[i])) break;
        sumJ += arrayJ[i];
    }

    vector<long long> arrayC(X);
    long long sumC = 0;
    for (int i = 0; i < X; ++i) {
        if (!(cin >> arrayC[i])) break;
        sumC += arrayC[i];
    }

    if (sumJ >= P || sumC >= P) {
        cout << "joey, essas regras estao piores que as do Fireball" << endl;
        return 0;
    }

    char goal;
    long long scoreJ = 0, scoreC = 0;
    int goalsJ = 0, goalsC = 0;

    while (cin >> goal) {
        if (goal == 'J') {
            scoreJ += arrayJ[goalsJ % X];
            goalsJ++;
        } else if (goal == 'C') {
            scoreC += arrayC[goalsC % X];
            goalsC++;
        }

        if (scoreJ >= P) {
            cout << "Well, you suck! But at least you suck at a man's game now" << endl;
            cout << "Joey: " << scoreJ << " (" << goalsJ << ")" << endl;
            cout << "Chandler: " << scoreC << " (" << goalsC << ")" << endl;
            break;
        } else if (scoreC >= P) {
            cout << "Good game, good game, good game" << endl;
            cout << "Chandler: " << scoreC << " (" << goalsC << ")" << endl;
            cout << "Joey: " << scoreJ << " (" << goalsJ << ")" << endl;
            break;
        }
    }

    return 0;
}