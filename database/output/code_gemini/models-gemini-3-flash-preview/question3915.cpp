/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Standard I/O optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B, C;
    // Reading A, B, and C as 64-bit integers to prevent overflow
    if (!(cin >> A >> B >> C)) return 0;

    bool found = false;
    bool firstMatch = true;

    // Operation 1: Quadrado (Square) - Based only on A as per instructions
    if (A * A == C) {
        if (firstMatch) {
            cout << "Quadrado Vitoris\n";
            firstMatch = false;
        } else {
            cout << "tambem Quadrado\n";
        }
        found = true;
    }

    // Operation 2: Resto (Remainder) - A % B = C
    if (B != 0 && (A % B == C)) {
        if (firstMatch) {
            cout << "Resto Vitoris\n";
            firstMatch = false;
        } else {
            cout << "tambem Resto\n";
        }
        found = true;
    }

    // Operation 3: Multi (Multiplication) - A * B = C
    if (A * B == C) {
        if (firstMatch) {
            cout << "Multi Vitoris\n";
            firstMatch = false;
        } else {
            cout << "tambem Multi\n";
        }
        found = true;
    }

    // Operation 4: Div (Division) - A / B = C (Integer Division)
    if (B != 0 && (A / B == C)) {
        if (firstMatch) {
            cout << "Div Vitoris\n";
            firstMatch = false;
        } else {
            cout << "tambem Div\n";
        }
        found = true;
    }

    // Operation 5: Soma (Addition) - A + B = C
    if (A + B == C) {
        if (firstMatch) {
            cout << "Soma Vitoris\n";
            firstMatch = false;
        } else {
            cout << "tambem Soma\n";
        }
        found = true;
    }

    // Operation 6: Sub (Subtraction) - A - B = C
    if (A - B == C) {
        if (firstMatch) {
            cout << "Sub Vitoris\n";
            firstMatch = false;
        } else {
            cout << "tambem Sub\n";
        }
        found = true;
    }

    // If no operations were found to be valid
    if (!found) {
        cout << "Impossivel vitores" << endl;
    }

    return 0;
}