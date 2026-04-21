/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    if (cin >> n >> x) {
        // N is the number of "digits" (elements) in the password.
        // D1 is the first digit, which must be a non-negative integer != X.
        // D2...DN must be 0 or 1, and all 0s must come before all 1s.
        // XOR(D1, D2, ..., DN) = X.
        // This implies D1 ^ XOR(D2, ..., DN) = X.
        // Let K be the number of 1s among D2...DN.
        // XOR(D2, ..., DN) is (K % 2).
        // So D1 ^ (K % 2) = X.
        // This means D1 = X ^ (K % 2).
        // Since D1 must not be X, we must have (K % 2) != 0, so K must be odd.
        // To maximize the number of 1s, we pick the largest odd K such that 
        // the remaining elements (N-1 total after D1) contain at least one 0 and one 1.
        // Slots available for D2...DN are (N-1).
        // Condition: at least one 0 and one 1 means 1 <= K <= (N-2).
        
        int k = n - 2; // Maximum possible number of 1s
        if (k % 2 == 0) {
            k--; // Ensure K is odd to satisfy D1 != X
        }
        
        long long d1 = x ^ 1; // Since K is odd, K%2 is 1
        
        cout << d1;
        
        int total_after = n - 1;
        int zeros = total_after - k;
        
        // Rule 4: 0's always come to the left of 1's
        for (int i = 0; i < zeros; ++i) {
            cout << " 0";
        }
        for (int i = 0; i < k; ++i) {
            cout << " 1";
        }
        cout << endl;
    }

    return 0;
}