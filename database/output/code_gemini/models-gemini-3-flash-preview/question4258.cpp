/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem: Reverse a list of numbers provided as a string.
 * Constraints: No .reverse() method, no Python-style end='' equivalent.
 * Time Complexity: O(N) where N is the number of elements.
 * Space Complexity: O(N) to store the elements.
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Printing the prompt exactly as requested in test cases
    cout << "Digite uma String de números: " << endl;

    string num;
    vector<string> elements;

    // Reading all numbers from the input string until EOF
    while (cin >> num) {
        elements.push_back(num);
    }

    // Checking if there are elements to process
    if (!elements.empty()) {
        cout << "O inverso dos números digitados é: ";
        
        // Manual reversal using a backward loop to comply with the restriction
        // of not using a built-in reverse function.
        for (int i = (int)elements.size() - 1; i >= 0; --i) {
            cout << elements[i];
            
            // Logic to handle comma separation and trailing period
            if (i > 0) {
                cout << ", ";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }

    return 0;
}
