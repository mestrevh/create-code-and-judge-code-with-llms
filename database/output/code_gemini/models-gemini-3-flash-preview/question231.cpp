/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cctype>

using namespace std;

/**
 * Parses an integer from the input stream.
 * Handles potential spaces between a sign and digits.
 */
long long readVal(char first) {
    long long sign = 1;
    if (first == '-' || first == '+') {
        bool isNeg = (first == '-');
        char c;
        // The problem description says integers are valid expressions, 
        // but sometimes formatting can have spaces like (- 1 ...).
        while (cin >> c && !isdigit(c));
        first = c;
        if (isNeg) sign = -1;
    }
    
    long long val = (long long)(first - '0');
    while (true) {
        int next_char = cin.peek();
        if (next_char != EOF && isdigit(next_char)) {
            char c;
            cin >> c;
            val = val * 10 + (long long)(c - '0');
        } else {
            break;
        }
    }
    return sign * val;
}

/**
 * Recursively parses the LISP-formatted tree.
 * returns true if the tree was empty '()', false otherwise.
 * updates the 'found' flag if a root-to-leaf path matches the target.
 */
bool solve(long long target, long long current, bool &found) {
    char c;
    // Every subtree starts with an opening parenthesis
    if (!(cin >> c)) return true;
    
    char next;
    // Check if the subtree is empty ()
    if (!(cin >> next)) return true;
    if (next == ')') return true;
    
    // If not empty, 'next' is the first character of the node value
    long long val = readVal(next);
    
    // Recursively parse left and right children
    bool left_empty = solve(target, current + val, found);
    bool right_empty = solve(target, current + val, found);
    
    // A node is a leaf only if both children are empty
    if (left_empty && right_empty) {
        if (current + val == target) {
            found = true;
        }
    }
    
    // Every non-empty subtree ends with a closing parenthesis
    cin >> c;
    return false;
}

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long target;
    // Process multiple test cases until target sum is -1000
    while (cin >> target && target != -1000) {
        bool found = false;
        // Start the recursive parsing from the root
        solve(target, 0, found);
        
        if (found) {
            cout << "sim\n";
        } else {
            cout << "nao\n";
        }
    }
    
    return 0;
}