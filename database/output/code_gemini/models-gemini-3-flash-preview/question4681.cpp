/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Checks if Vinícius has a domino piece (a, b).
 * Each piece in the vector is a 2-digit integer where the digits are the sides.
 */
bool has_piece(int a, int b, const vector<int>& pieces) {
    for (int p : pieces) {
        int d1 = p / 10;
        int d2 = p % 10;
        if ((d1 == a && d2 == b) || (d1 == b && d2 == a)) {
            return true;
        }
    }
    return false;
}

/**
 * Checks if Vinícius has any piece that has the digit 'x' on one side.
 */
bool has_piece_with_digit(int x, const vector<int>& pieces) {
    for (int p : pieces) {
        if (p / 10 == x || p % 10 == x) {
            return true;
        }
    }
    return false;
}

int main() {
    // Standard I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Read n domino pieces
    vector<int> pieces(n);
    for (int i = 0; i < n; i++) {
        cin >> pieces[i];
    }

    // Read current open ends
    int L, R;
    if (!(cin >> L >> R)) return 0;

    // Read command string (action + 6 digits)
    string s;
    if (!(cin >> s)) return 0;

    // String format: [action][3 digits num1][3 digits num2]
    int len = s.length();
    if (len < 6) return 0;

    string n1_str = s.substr(len - 6, 3);
    string n2_str = s.substr(len - 3, 3);
    
    int n1 = stoi(n1_str);
    int n2 = stoi(n2_str);
    
    // Calculate x = num1 / num2
    int x = 0;
    if (n2 != 0) x = n1 / n2;

    // Extract the action code
    string action = s.substr(0, len - 6);

    bool possible = false;

    if (action == "manbr") {
        /* 
           Action: manbr (Close both ends to x)
           A move is possible if both ends end up being x.
           Since we only play one piece:
           1. If L is already x, we need a piece (R, x) to change R to x.
           2. If R is already x, we need a piece (L, x) to change L to x.
        */
        if (L == x) {
            if (has_piece(R, x, pieces)) possible = true;
        } else if (R == x) {
            if (has_piece(L, x, pieces)) possible = true;
        }
    } else if (action == "rpf") {
        /* 
           Action: rpf (Place x on the table)
           Possible if we have a piece that connects to one end and has x on the other.
        */
        if (has_piece(L, x, pieces) || has_piece(R, x, pieces)) {
            possible = true;
        }
    } else if (action == "rrs") {
        /* 
           Action: rrs (Remove x and replace with something else)
           Possible if one of the ends is x and we have any piece matching x.
        */
        if (L == x || R == x) {
            if (has_piece_with_digit(x, pieces)) {
                possible = true;
            }
        }
    } else if (action == "dsfs") {
        /* 
           Action: dsfs (Do nothing)
           Always possible.
        */
        possible = true;
    }

    // Output results
    if (possible) {
        cout << "ai maezinha" << endl;
    } else {
        cout << "cade o douze" << endl;
    }

    return 0;
}
