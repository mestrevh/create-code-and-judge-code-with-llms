/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem L6Q3 - Jarvis
 * The problem asks to calculate a value based on a recursive function applied to a list.
 * f(head, tail) = head op f(tail)
 * f(last_element) = last_element
 * For op = '+', result is sum of all elements.
 * For op = '-', result is A1 - (A2 - (A3 - (... - AN))).
 * Given N is small (up to 30), O(N) is optimal.
 */

int main() {
    // Optimize standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Read the size of the list
    if (!(cin >> n)) return 0;

    // Read the generator key elements
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Parse the operation from the function string "x op y"
    char op = '+';
    string part;
    while (cin >> part) {
        bool found = false;
        for (char c : part) {
            if (c == '+' || c == '-') {
                op = c;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    // Edge case: empty list (though constraints say 1 <= N <= 30)
    if (n <= 0) return 0;

    /**
     * The recursive function f(head, tail) = head op f(tail) can be 
     * computed iteratively from the end of the list to the beginning.
     * Base case: f(AN) = AN
     * Step: f(Ai...AN) = Ai op f(Ai+1...AN)
     */
    long long result = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        if (op == '+') {
            result = a[i] + result;
        } else {
            result = a[i] - result;
        }
    }

    // Output the final password
    cout << result << endl;

    return 0;
}