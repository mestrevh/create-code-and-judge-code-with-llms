/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

/**
 * Problem: Christmas Party Organization Poll
 * Constraints: 11 voters, 2 choices each (Day, Location)
 * Time complexity: O(N), where N is the number of voters.
 * Space complexity: O(1).
 */

string to_upper_normalized(string s) {
    for (auto &c : s) c = (char)toupper((unsigned char)c);
    return s;
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sexta_votes = 0;
    int domingo_votes = 0;
    int bar_votes = 0;
    int praia_votes = 0;

    const int NUM_VOTERS = 11;

    for (int i = 0; i < NUM_VOTERS; ++i) {
        string day_vote, place_vote;
        
        if (!(cin >> day_vote >> place_vote)) break;

        // Normalize day choice to check counts
        string day_norm = to_upper_normalized(day_vote);
        if (day_norm == "SEXTA") {
            sexta_votes++;
        } else if (day_norm == "DOMINGO") {
            domingo_votes++;
        }

        // Normalize place choice to check counts
        string place_norm = to_upper_normalized(place_vote);
        if (place_norm == "BAR") {
            bar_votes++;
        } else if (place_norm == "PRAIA") {
            praia_votes++;
        }
    }

    // Output the winning day
    if (sexta_votes > domingo_votes) {
        cout << "SEXTA" << "\n";
    } else {
        cout << "DOMINGO" << "\n";
    }

    // Output the winning location
    if (bar_votes > praia_votes) {
        cout << "BAR" << "\n";
    } else {
        cout << "PRAIA" << "\n";
    }

    return 0;
}
_
