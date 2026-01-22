/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

double calculate(int A, int B, char op) {
    switch (op) {
        case '#':
            return pow(A, B) * pow(B, A);
        case '@':
            return pow(A, B) / pow(B, A);
        case '&':
            return B * sqrt(A) + A * sqrt(B);
        case '%':
            return B * sqrt(A) - A * sqrt(B);
        default:
            return 0;
    }
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    while (N--) {
        string line;
        getline(cin, line);
        char op;
        int A, B;
        stringstream ss(line);
        ss >> A >> op >> B;
        double result = calculate(A, B, op);
        cout << fixed << setprecision(2) << result << endl;
    }
    return 0;
}
