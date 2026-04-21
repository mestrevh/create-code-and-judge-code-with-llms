/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem: Satellite reconfiguration based on quadrant subdivision.
 * Complexity: O(T^2) to find the star, O(log T) to generate commands.
 * Quadrants are based on Cartesian mapping:
 * 1: Top-Right
 * 2: Top-Left
 * 3: Bottom-Left
 * 4: Bottom-Right
 */

int main() {
    // Standard I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    int starR = -1, starC = -1;

    // Read the matrix and locate the '*' character
    for (int i = 0; i < T; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < (int)row.length(); ++j) {
            if (row[j] == '*') {
                starR = i;
                starC = j;
            }
        }
    }

    string commands = "";
    int currentSize = T;
    int r = starR;
    int c = starC;

    // Iterate through subdivisions until reaching a 1x1 area
    while (currentSize > 1) {
        int mid = currentSize / 2;
        
        // Determine which quadrant the star is in
        if (r < mid && c >= mid) {
            // Quadrant 1: Top-Right
            commands += '1';
            c -= mid;
        } else if (r < mid && c < mid) {
            // Quadrant 2: Top-Left
            commands += '2';
        } else if (r >= mid && c < mid) {
            // Quadrant 3: Bottom-Left
            commands += '3';
            r -= mid;
        } else if (r >= mid && c >= mid) {
            // Quadrant 4: Bottom-Right
            commands += '4';
            r -= mid;
            c -= mid;
        }
        
        currentSize /= 2;
    }

    // Append '0' to finalize configuration as per instructions
    commands += '0';

    cout << commands << endl;

    return 0;
}