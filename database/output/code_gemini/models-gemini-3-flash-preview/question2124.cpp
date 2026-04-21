/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Using __int128 for P and forces to handle values exceeding 64-bit limits safely
typedef __int128 int128;

// Function to convert string to __int128
int128 strTo128(string s) {
    int128 res = 0;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            res = res * 10 + (int128)(c - '0');
        }
    }
    return res;
}

int128 memo[35];
bool visited[35];

// Recursive function to calculate the magnitude of the force F(n)
// n=0: concentration C, n=1: Tank efficiency T
// n>=2: Pell-like recurrence F(n) = 2*F(n-1) + F(n-2)
int128 get_F(int n, int128 C, int128 T) {
    if (n == 0) return C;
    if (n == 1) return T;
    if (visited[n]) return memo[n];
    visited[n] = true;
    return memo[n] = 2 * get_F(n - 1, C, T) + get_F(n - 2, C, T);
}

// Recursive function to simulate attempts and blood loss
void solve(int n, int128 C, int128 T, int128 P) {
    // Each attempt costs 12ml. Eleven faints if loss > 300ml.
    // Success happens when F(n) >= weight P.
    if ((n + 1) * 12 > 300) {
        cout << "Eleven ficou fraca demais e acabou desmaiando" << endl;
        return;
    }
    
    if (get_F(n, C, T) >= P) {
        // Successful attempt
        cout << "Eleven perdeu " << (int)((n + 1) * 12) << "ml de sangue." << endl;
        return;
    }
    
    // Fail current attempt, move to the next one
    solve(n + 1, C, T, P);
}

int main() {
    // Competitive programming standard optimization for C++ I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> tokens;
    string s;
    // Reading all numerical tokens from input to handle optional T
    while (cin >> s) {
        tokens.push_back(s);
    }

    if (tokens.size() < 2) return 0;

    int128 C, T, P;
    if (tokens.size() == 2) {
        // Format: C P (T is not presented, default to 0)
        C = strTo128(tokens[0]);
        T = 0;
        P = strTo128(tokens[1]);
    } else {
        // Format: C T P
        C = strTo128(tokens[0]);
        T = strTo128(tokens[1]);
        P = strTo128(tokens[2]);
    }

    // Initialize memoization for recursive Pell sequence calculation
    for (int i = 0; i < 35; i++) {
        visited[i] = false;
    }

    // Start simulation from the first attempt (n=0)
    solve(0, C, T, P);

    return 0;
}