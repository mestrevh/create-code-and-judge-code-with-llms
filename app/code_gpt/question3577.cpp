/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    string str;
    cin >> str;

    int cntC = 0, cntB = 0, cntE = 0, cntD = 0;

    for (char ch : str) {
        if (ch == 'C') cntC++;
        else if (ch == 'B') cntB++;
        else if (ch == 'E') cntE++;
        else if (ch == 'D') cntD++;
    }

    int currentX = cntE - cntD;
    int currentY = cntB - cntC;

    if (currentX == x && currentY == y) {
        cout << "S" << endl;
    } else {
        if (abs(currentX - x) <= cntE + cntD && abs(currentY - y) <= cntB + cntC) {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}
