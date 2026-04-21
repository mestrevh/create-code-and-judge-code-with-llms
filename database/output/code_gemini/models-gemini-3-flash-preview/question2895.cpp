/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double targetX, targetY;
    if (!(cin >> targetX >> targetY)) {
        return 0;
    }

    string closestName = "";
    double minDistanceSq = numeric_limits<double>::max();
    bool found = false;

    double curX, curY;
    string curName;
    while (cin >> curX >> curY >> curName) {
        double dx = targetX - curX;
        double dy = targetY - curY;
        double dSq = dx * dx + dy * dy;

        if (dSq < minDistanceSq) {
            minDistanceSq = dSq;
            closestName = curName;
            found = true;
        }
    }

    if (found && minDistanceSq < 100.0) {
        cout << "O aluno novo é mais parecido com " << closestName << endl;
    } else {
        cout << "Aparentemente ele não é tão chato assim" << endl;
    }

    return 0;
}