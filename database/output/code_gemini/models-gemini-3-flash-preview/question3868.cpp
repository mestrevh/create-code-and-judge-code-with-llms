/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(const string& s) {
    if (s.empty()) return true;
    int i = 0, j = (int)s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> initial_grid(n, string(n, ' '));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> initial_grid[i][j];
        }
    }

    int k;
    if (!(cin >> k)) return 0;

    int pass_count = 0;
    for (int i = 0; i < k; ++i) {
        int t;
        if (!(cin >> t)) break;
        string s;
        if (t > 0) {
            cin >> s;
        } else {
            s = "";
        }

        if (is_palindrome(s)) {
            pass_count++;
            continue;
        }

        vector<string> grid = initial_grid;
        int r = 0, c = 0;
        bool failed = false;

        // Based on the problem, players are starting from (0,0).
        // If (0,0) was out of bounds or a hole initially, we would check here.
        // However, the input grid contains 'x' or 'o', and n >= 1.

        for (char move : s) {
            int oldr = r, oldc = c;
            
            if (move == 'C') r--;
            else if (move == 'B') r++;
            else if (move == 'D') c++;
            else if (move == 'E') c--;

            // When a player passes over an unstable point ('x'), it becomes a hole (' ')
            if (grid[oldr][oldc] == 'x') {
                grid[oldr][oldc] = ' ';
            }

            // Fall conditions: out of bounds or step into a hole
            if (r < 0 || r >= n || c < 0 || c >= n) {
                failed = true;
                break;
            }
            if (grid[r][c] == ' ') {
                failed = true;
                break;
            }
        }

        if (!failed) {
            pass_count++;
        }
    }

    cout << pass_count << endl;

    return 0;
}