/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;
    cin >> x >> y;

    bool inA = (pow(x - 1, 2) + pow(y - 1, 2) <= 1);
    bool inB = (pow(x - 2, 2) + pow(y - 1, 2) <= 1);

    if (inA && inB)
        cout << "Interior A,B";
    else if (inA)
        cout << "Interior A";
    else if (inB)
        cout << "Interior B";
    else
        cout << "Exterior";

    return 0;
}
