/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/**
 * Competitive Programming Solution: Pilhas com Listas
 * 
 * Strategy:
 * - Use a std::vector<std::vector<int>> to represent a stack of variable-sized lists.
 * - This provides O(1) push and pop operations (amortized) and handles dynamic allocation.
 * - For input parsing, read the command then use getline to capture the entire line 
 *   of integers for PUSH operations.
 * - Use Fast I/O to ensure performance within the 2-second time limit.
 */

int main() {
    // Optimize standard I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> stack;
    string cmd;

    // Read commands until EOF
    while (cin >> cmd) {
        if (cmd == "PUSH") {
            // Consume the remaining newline/whitespace on the command line
            string dummy;
            getline(cin, dummy);
            
            // Read the next full line containing the variable number of integers
            string line;
            if (getline(cin, line)) {
                vector<int> v;
                stringstream ss(line);
                int val;
                while (ss >> val) {
                    v.push_back(val);
                }
                stack.push_back(v);
            }
        } else if (cmd == "POP") {
            if (stack.empty()) {
                cout << "EMPTY STACK\n";
            } else {
                // Get the list at the top of the stack
                const vector<int>& topList = stack.back();
                
                // Print elements separated by spaces, avoiding trailing space
                for (size_t i = 0; i < topList.size(); ++i) {
                    if (i > 0) cout << " ";
                    cout << topList[i];
                }
                cout << "\n";
                
                // Remove the top list from the stack
                stack.pop_back();
            }
        }
    }

    return 0;
}