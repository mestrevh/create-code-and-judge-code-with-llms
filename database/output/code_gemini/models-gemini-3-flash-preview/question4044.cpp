/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Fast I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string keyword, encoded;
    // Reading both keyword and encoded message
    if (!(cin >> keyword >> encoded)) return 0;

    // Step 1: Calculate the sum of ASCII values of the keyword (X)
    long long x_sum = 0;
    for (char c : keyword) {
        x_sum += (unsigned char)c;
    }

    // Step 2: Calculate the "chave" (X mod 26)
    // A=0, B=1, ..., Z=25
    int chave = x_sum % 26;

    int letter_idx = 0;
    int k_len = keyword.length();
    
    // Step 3: Iterate through the encoded message and decode it
    for (char c : encoded) {
        if (c >= 'A' && c <= 'Z') {
            // For the n-th letter of the encoded message, use the n-th letter of the keyword
            // Use modulo to wrap around the keyword if it's shorter than the message letters count
            int k_val = keyword[letter_idx % k_len] - 'A';
            
            // dist = |k_val - chave| (módulo da subtração)
            int dist = k_val - chave;
            if (dist < 0) dist = -dist;
            
            // Decoded character: go back "dist" letters in the alphabet
            int p_val = c - 'A';
            int d_val = (p_val - dist) % 26;
            // Handle negative results for modulo
            if (d_val < 0) d_val += 26;
            
            cout << (char)(d_val + 'A');
            // Only increment the keyword index when a letter is decoded
            letter_idx++;
        } else {
            // Special characters decoding
            if (c == '_') {
                cout << ' ';
            } else if (c == '#') {
                cout << '.';
            } else if (c == '&') {
                cout << ',';
            } else {
                // Keep other characters as they are if they somehow appear
                cout << c;
            }
        }
    }
    cout << "\n";

    return 0;
}

