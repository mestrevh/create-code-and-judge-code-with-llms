/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

double calculateDiagonal(double width, double length) {
    return sqrt(width * width + length * length);
}

int main() {
    int n;
    cin >> n;

    vector<double> diagonals;
    double maxDimension;
    string shape;
    for (int i = 0; i < n; ++i) {
        cin >> shape;
        if (shape == "RETANGULAR") {
            double width, length;
            cin >> width >> length;
            diagonals.push_back(calculateDiagonal(width, length));
        } else if (shape == "CIRCULAR") {
            double radius;
            cin >> radius; // skip the radius input
        }
    }
    
    cin >> maxDimension;
    
    bool foundAny = false;
    for (double d : diagonals) {
        if (d <= maxDimension) {
            foundAny = true;
            cout << fixed << setprecision(2) << d << endl;
        }
    }
    
    if (!foundAny) {
        cout << -1 << endl;
    }

    return 0;
}
