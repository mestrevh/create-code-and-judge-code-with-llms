/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    // Reading input. Using cin >> s because the problem mentions "uma palavra" (one word).
    if (!(cin >> s)) {
        return 0;
    }

    string even = "";
    string odd = "";

    // Iterate through the string to separate even and odd position characters.
    // Based on the examples, index 0 is considered an even position.
    for (int i = 0; i < (int)s.length(); ++i) {
        if (i % 2 == 0) {
            even += s[i];
        } else {
            odd += s[i];
        }
    }

    // Creating the reversed string.
    string rev = s;
    reverse(rev.begin(), rev.end());

    // Printing the result in the exact format specified by the test cases.
    cout << "Somente posições pares: " << even << "\n";
    cout << "Somente posições ímpares: " << odd << "\n";
    cout << "De trás para frente: " << rev << endl;

    return 0;
}