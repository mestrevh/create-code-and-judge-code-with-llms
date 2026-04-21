/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int counts[256] = {0};
    char c;
    
    // Read 5 characters as specified in the input format
    for (int i = 0; i < 5; ++i) {
        if (cin >> c) {
            counts[(unsigned char)c]++;
        }
    }

    // A sequence of characters can form a palindrome if and only if
    // at most one character type has an odd frequency (for odd total length).
    // For a total length of 5, there must be exactly 1, 3, or 5 characters with odd frequencies.
    // Only 1 odd frequency allows the formation of a palindrome.
    int odd_frequencies = 0;
    for (int i = 0; i < 256; ++i) {
        if (counts[i] % 2 != 0) {
            odd_frequencies++;
        }
    }

    if (odd_frequencies <= 1) {
        cout << "sim" << endl;
    } else {
        cout << "nao" << endl;
    }

    return 0;
}
