/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line)) {
        return 0;
    }

    // Using a frequency array for the extended ASCII range (0-255)
    int freq[256] = {0};

    // Fill the frequency map based on characters in the line
    for (unsigned char c : line) {
        freq[c]++;
    }

    // Output characters and their frequencies in descending ASCII order
    for (int i = 255; i >= 0; --i) {
        if (freq[i] > 0) {
            cout << (char)i << " " << freq[i] << "\n";
        }
    }

    return 0;
}