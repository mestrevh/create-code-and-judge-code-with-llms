/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem: Corona Ep 8
 * Task: Verify if 3 points on a Cartesian plane maintain a minimum distance of 2 units from each other.
 * Logic: Calculate squared distances between all pairs (A-B, B-C, A-C) and check if each is >= 4.0.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double ax, ay, bx, by, cx, cy;

    // Read coordinates for three clients (ax, ay), (bx, by), (cx, cy)
    if (!(cin >> ax >> ay >> bx >> by >> cx >> cy)) {
        return 0;
    }

    // Lambda to calculate squared Euclidean distance between two points
    auto getDistSq = [](long double x1, long double y1, long double x2, long double y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };

    // Distances squared for all three pairs
    long double dAB2 = getDistSq(ax, ay, bx, by);
    long double dBC2 = getDistSq(bx, by, cx, cy);
    long double dAC2 = getDistSq(ax, ay, cx, cy);

    // Minimum distance required is 2 units, so squared distance must be >= 4.
    // Using a small epsilon to handle potential floating point precision issues.
    const long double EPS = 1e-12;
    const long double MIN_DIST_SQ = 4.0 - EPS;

    if (dAB2 >= MIN_DIST_SQ && dBC2 >= MIN_DIST_SQ && dAC2 >= MIN_DIST_SQ) {
        cout << "POSICAO VALIDA" << endl;
    } else {
        cout << "POSICAO INVALIDA" << endl;
    }

    return 0;
}