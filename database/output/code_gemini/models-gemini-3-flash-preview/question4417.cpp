/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    // Standard I/O optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    unsigned long long B;

    // Read N (size of the NxN board) and B (the decimal value to be bit-mapped)
    // Using unsigned long long to accommodate up to 64 bits (common for N=8)
    if (cin >> N >> B) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                // Check if the current least significant bit is 1
                if (B & 1) {
                    cout << 'x';
                } else {
                    cout << '-';
                }
                // Right shift B to process the next bit (move to next column/row)
                // This processes bits from least significant to most significant
                B >>= 1;
            }
            // Move to the next row of the board
            cout << '\n';
        }
    }

    return 0;
}