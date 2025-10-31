/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int main() {
    string point, denominator;
    getline(cin, point);
    getline(cin, denominator);

    int x, y;
    sscanf(point.c_str(), "(%d,%d)", &x, &y);

    double value = 0;
    stringstream ss(denominator);
    string term;

    while (ss >> term) {
        if (term == "x") {
            value += x;
        } else if (term == "y") {
            value += y;
        } else if (term.find('x') != string::npos) {
            int coeff = 1, powx = 1;
            sscanf(term.c_str(), "%dx^%d", &coeff, &powx);
            value += coeff * pow(x, powx);
        } else if (term.find('y') != string::npos) {
            int coeff = 1, powy = 1;
            sscanf(term.c_str(), "%dy^%d", &coeff, &powy);
            value += coeff * pow(y, powy);
        } else if (term.find('-') != string::npos) {
            int coeff = 1, pow_term = 1;
            sscanf(term.c_str(), "%dx^%d", &coeff, &pow_term);
            value -= coeff * pow(x, pow_term);
        }
    }

    if (value != 0) {
        cout << "a função está definida em (" << x << "," << y << ")" << endl;
    } else {
        cout << "a função não está definida em (" << x << "," << y << ") .-." << endl;
    }
    
    return 0;
}
