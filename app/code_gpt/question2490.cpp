/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double Ax, Ay, Bx, By, Cx, Cy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;

    double AB = sqrt(pow(Bx - Ax, 2) + pow(By - Ay, 2));
    double BC = sqrt(pow(Cx - Bx, 2) + pow(Cy - By, 2));
    double CA = sqrt(pow(Ax - Cx, 2) + pow(Ay - Cy, 2));

    cout << fixed << setprecision(2);
    cout << "A-B: " << AB << endl;
    cout << "B-C: " << BC << endl;
    cout << "C-A: " << CA << endl;

    return 0;
}
