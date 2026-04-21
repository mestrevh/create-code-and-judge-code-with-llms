/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n1, n2;
    int p1, s1, g1;
    int p2, s2, g2;

    if (!(cin >> n1 >> p1 >> s1 >> g1)) return 0;
    if (!(cin >> n2 >> p2 >> s2 >> g2)) return 0;

    int winner = 0; // 0: Draw, 1: Team 1, 2: Team 2

    if (p1 > p2) {
        winner = 1;
    } else if (p2 > p1) {
        winner = 2;
    } else {
        if (s1 > s2) {
            winner = 1;
        } else if (s2 > s1) {
            winner = 2;
        } else {
            if (g1 > g2) {
                winner = 1;
            } else if (g2 > g1) {
                winner = 2;
            } else {
                winner = 0;
            }
        }
    }

    if (winner == 0) {
        cout << "EMPATE" << endl;
    } else {
        string name = (winner == 1) ? n1 : n2;
        for (char &c : name) {
            c = (char)tolower((unsigned char)c);
        }
        cout << name << endl;
    }

    return 0;
}