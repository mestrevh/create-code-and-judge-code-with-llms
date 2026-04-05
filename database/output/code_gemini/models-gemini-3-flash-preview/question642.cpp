/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Competitive Programming Solution
 * Spiral Enumeration and Border Side Determination
 * Complexity: O(N * (65536 + K)) where N=100, K=1000.
 */

struct Point {
    int x, y;
};

// Function to calculate the sign of the point with respect to the line y = ax + b
// Skipping points where ax - y + b == 0
inline bool is_on_border(long long a, long long b, int x, int y) {
    return (a * x - y + b) == 0;
}

inline bool get_side(long long a, long long b, int x, int y) {
    return (a * x - y + b) > 0;
}

void solve_test_case(int caseNum) {
    long long a, b;
    if (!(cin >> a >> b)) return;

    // Use a vector of bools to store side (true for positive, false for negative)
    vector<bool> side_signs;
    side_signs.reserve(65537);

    int x = 0, y = 0;
    // Spiral starting point (0,0)
    if (!is_on_border(a, b, x, y)) {
        side_signs.push_back(get_side(a, b, x, y));
    }

    int L = 1;
    // Standard clockwise spiral: Left L, Up L, then L++, Right L, Down L, then L++
    while (side_signs.size() <= 65535) {
        // Move Left L steps
        for (int i = 0; i < L && side_signs.size() <= 65535; ++i) {
            x--;
            if (!is_on_border(a, b, x, y)) {
                side_signs.push_back(get_side(a, b, x, y));
            }
        }
        // Move Up L steps
        for (int i = 0; i < L && side_signs.size() <= 65535; ++i) {
            y++;
            if (!is_on_border(a, b, x, y)) {
                side_signs.push_back(get_side(a, b, x, y));
            }
        }
        L++;
        // Move Right L steps
        for (int i = 0; i < L && side_signs.size() <= 65535; ++i) {
            x++;
            if (!is_on_border(a, b, x, y)) {
                side_signs.push_back(get_side(a, b, x, y));
            }
        }
        // Move Down L steps
        for (int i = 0; i < L && side_signs.size() <= 65535; ++i) {
            y--;
            if (!is_on_border(a, b, x, y)) {
                side_signs.push_back(get_side(a, b, x, y));
            }
        }
        L++;
    }

    int K;
    cin >> K;
    cout << "Caso " << caseNum << "\n";
    while (K--) {
        int m, n;
        cin >> m >> n;
        // Access precalculated signs
        if (side_signs[m] == side_signs[n]) {
            cout << "Mesmo lado da fronteira\n";
        } else {
            cout << "Lados opostos da fronteira\n";
        }
    }
}

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numCases;
    if (!(cin >> numCases)) return 0;
    for (int i = 1; i <= numCases; ++i) {
        solve_test_case(i);
    }

    return 0;
}