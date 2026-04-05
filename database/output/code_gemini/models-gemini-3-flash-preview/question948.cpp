/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * Competitive Programming Solution
 * Problem: Fitting Blocks (Encaixando blocos)
 * Complexity: O(N) per test case
 */

struct Piece {
    bool isBlock;
    double diagonal;
};

int main() {
    // Standard I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Process while there are test cases (multiple entries support)
    while (cin >> n) {
        vector<Piece> pieces;
        pieces.reserve(n);

        for (int i = 0; i < n; ++i) {
            string type;
            cin >> type;
            if (type == "CIRCULAR") {
                double r;
                cin >> r;
                // For cylinders, max dimension is 2*r. However, they are not printed.
                // We only store that it's not a block.
                pieces.push_back({false, 2.0 * r});
            } else if (type == "RETANGULAR") {
                double b, l;
                cin >> b >> l;
                // For blocks, max dimension is the diagonal of the base rectangle
                double diag = sqrt(b * b + l * l);
                pieces.push_back({true, diag});
            }
        }

        double d;
        // After reading n pieces, read the compartment's max dimension D
        if (!(cin >> d)) break;

        bool any_found = false;
        for (const auto& p : pieces) {
            if (p.isBlock) {
                // A piece fits if the compartment dimension is greater than the piece dimension
                // Rule: D > PieceMaxDim
                if (d > p.diagonal) {
                    cout << fixed << setprecision(2) << p.diagonal << "\n";
                    any_found = true;
                }
            }
        }

        // If no block fits (or no blocks were provided), output -1
        if (!any_found) {
            cout << -1 << "\n";
        }
    }

    return 0;
}