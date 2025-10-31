/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int P, X;
    cin >> P >> X;
    
    vector<int> arrayJ(X), arrayC(X);
    for (int i = 0; i < X; i++) cin >> arrayJ[i];
    for (int i = 0; i < X; i++) cin >> arrayC[i];
    
    string G;
    cin >> G;

    int joeyScore = 0, chandlerScore = 0;
    int joeyGoals = 0, chandlerGoals = 0;

    for (int i = 0; i < G.size(); i++) {
        int idx = i % X;
        if (G[i] == 'J') {
            joeyScore += arrayJ[idx];
            joeyGoals++;
        } else {
            chandlerScore += arrayC[idx];
            chandlerGoals++;
        }
    }

    if (joeyScore >= P || chandlerScore >= P) {
        cout << "joey, essas regras estao piores que as do Fireball" << endl;
    } else if (joeyScore > chandlerScore) {
        cout << "Well, you suck! But at least you suck at a man's game now" << endl;
        cout << "Joey: " << joeyScore << " (" << joeyGoals << ")" << endl;
        cout << "Chandler: " << chandlerScore << " (" << chandlerGoals << ")" << endl;
    } else {
        cout << "Good game, good game, good game" << endl;
        cout << "Chandler: " << chandlerScore << " (" << chandlerGoals << ")" << endl;
        cout << "Joey: " << joeyScore << " (" << joeyGoals << ")" << endl;
    }

    return 0;
}
