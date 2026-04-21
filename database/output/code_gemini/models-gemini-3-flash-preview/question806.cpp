/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Read the number of text lines
    if (!(cin >> n)) return 0;

    // Consume the remaining newline character after reading the integer N
    string dummy;
    getline(cin, dummy);

    // Frequency array for all 256 possible byte values (standard and extended ASCII)
    int counts[256] = {0};

    // Read exactly N lines and update character counts
    for (int i = 0; i < n; ++i) {
        string line;
        if (!getline(cin, line)) break;
        for (unsigned char c : line) {
            counts[c]++;
        }
    }

    // Read the (N+1)-th line which contains the characters to be queried
    string query;
    if (getline(cin, query)) {
        // For each character in the query string, output its calculated frequency
        for (unsigned char c : query) {
            cout << (char)c << " = " << counts[c] << "\n";
        }
    }

    return 0;
}