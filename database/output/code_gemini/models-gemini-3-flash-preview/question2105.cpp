/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problem: Millennium Falcon Obstacle Avoidance
 * Logic: 
 * - An Upper Triangular matrix (Triangular Superior) has zeros below the main diagonal.
 *   For a 3x3 matrix, these are indices (1,0), (2,0), and (2,1).
 *   Output: "Por baixo"
 * - A Lower Triangular matrix (Triangular Inferior) has zeros above the main diagonal.
 *   For a 3x3 matrix, these are indices (0,1), (0,2), and (1,2).
 *   Output: "Por cima"
 * - If neither condition is met, output: "Nao pode atravessar"
 * - Any 0 outside the required triangular area is treated as solid and does not affect the type.
 */

int main() {
    // Optimize standard I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long mat[9];
    // Read the stream of matrices (9 elements each)
    while (cin >> mat[0]) {
        for (int i = 1; i < 9; ++i) {
            if (!(cin >> mat[i])) break;
        }

        // Indices in a 3x3 matrix:
        // 0 1 2
        // 3 4 5
        // 6 7 8

        // Check for Triangular Superior (zeros below the diagonal: 3, 6, 7)
        bool isSuperior = (mat[3] == 0 && mat[6] == 0 && mat[7] == 0);
        
        // Check for Triangular Inferior (zeros above the diagonal: 1, 2, 5)
        bool isInferior = (mat[1] == 0 && mat[2] == 0 && mat[5] == 0);

        if (isSuperior) {
            // Case for Upper Triangular matrix
            cout << "Por baixo\n";
        } else if (isInferior) {
            // Case for Lower Triangular matrix
            cout << "Por cima\n";
        } else {
            // Neither case applies
            cout << "Nao pode atravessar\n";
        }
    }

    return 0;
}